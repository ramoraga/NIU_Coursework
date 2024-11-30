//
//  InsertAlbumView.swift
//  Album
//
//  Created by Rami Lake on 4/30/22.
//

import SwiftUI

struct InsertAlbumView: View {
    @Environment(\.managedObjectContext) var dbContext
    @Environment(\.dismiss) var dismiss
    @State private var inputTitle = ""
    @State private var inputYear = ""
    @State private var inputArtist = ""
    @State private var selectedImage: UIImage? = nil
    @State private var showPhotoLib = false

    var body: some View {
        VStack(spacing: 12) {
            HStack {
                Text("Title:")
                TextField("Insert Title", text: $inputTitle)
                    .textFieldStyle(.roundedBorder)
            }
            
            HStack {
                Text("Year:")
                TextField("Insert Year", text: $inputYear)
                    .textFieldStyle(.roundedBorder)
            }
            
            
            HStack {
                Text("Artist:")
                TextField("Insert Artist", text: $inputArtist)
                    .textFieldStyle(.roundedBorder)
            }
            .frame(minWidth: 0, maxWidth: .infinity, alignment: .leading)
            
            Button(action: {showPhotoLib = true}, label: {
                HStack {
                    Image(systemName: "photo")
                        .font(.system(size: 20))
                    
                    Text("Select Album Cover")
                        .font(.headline)
                }
                .padding()
                .background(Color.blue)
                .foregroundColor(.white)
                .cornerRadius(20)
                .padding()
            })

            Image(uiImage: (selectedImage ?? UIImage(named: "nopicture")!))
                .resizable()
                .scaledToFit()
                .cornerRadius(5)
                .shadow(color: .gray, radius: 5, x: 5, y: 5)
                .padding(.horizontal)
            
            Spacer()
        }
        .padding()
        .navigationBarTitle("Add Album")
        .toolbar {
            ToolbarItem(placement:.navigationBarTrailing) {
                Button("Save") {
                    let newTitle = inputTitle
                        .trimmingCharacters(in: .whitespaces)
                    let newArtist = inputArtist
                        .trimmingCharacters(in: .whitespaces)
                    let newYear = Int32(inputYear)
                    if !newTitle.isEmpty && newYear != nil {
                        Task (priority: .high) {
                            await storeAlbum(title: newTitle, artist: newArtist ,year: newYear!)
                        }
                    }
                }
            }
        }
        .sheet(isPresented: $showPhotoLib) {
            ImagePicker(sourceType: .photoLibrary, selectedImage: $selectedImage)
        }
    }
    
    
    func storeAlbum(title: String, artist: String, year: Int32) async {
        await dbContext.perform {
            let newAlbum = Album(context: dbContext)
            newAlbum.title = title
            newAlbum.year = year
            newAlbum.artist = artist
            
            if (selectedImage != nil) {
                newAlbum.cover = selectedImage!.pngData()
                newAlbum.thumbnail = selectedImage!.pngData()
            } else {
                newAlbum.cover = UIImage(named: "albumcover")?.pngData()
                newAlbum.thumbnail = UIImage(named: "albumthumbnail")?.pngData()
            }
            
            do {
                try dbContext.save()
                dismiss()
            } catch {
                print(error)
            }
        }
    }
}

struct InsertAlbumView_Previews: PreviewProvider {
    static var previews: some View {
        InsertAlbumView()
            .environment(\.managedObjectContext, PersistenceController.preview.container.viewContext)
    }
}
