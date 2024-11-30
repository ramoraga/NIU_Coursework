//
//  ModifyAlbumView.swift
//  Album
//
//  Created by Rami Lake on 5/1/22.
//

import SwiftUI

struct ModifyAlbumView: View {
    @Environment(\.managedObjectContext) var dbContext
    @Environment(\.dismiss) var dismiss
    @State private var inputTitle = ""
    @State private var inputYear = ""
    @State private var inputArtist = ""
    @State private var valuesLoaded: Bool = false
    @State private var selectedImage: UIImage? = nil
    @State private var showPhotoLib = false

    let album: Album?
    
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
                TextField("Insert Arttist", text: $inputArtist)
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
        .navigationBarTitle("Modify Album")
        .toolbar {
            ToolbarItem(placement: .navigationBarTrailing) {
                Button("Save") {
                    let newTitle = inputTitle.trimmingCharacters(in: .whitespaces)
                    let newArtist = inputArtist.trimmingCharacters(in: .whitespaces)
                    let year = Int32(inputYear)
                    if !newTitle.isEmpty && year != nil {
                        Task(priority: .high) {
                            await saveBook(title: newTitle, artist: newArtist, year: year!)
                        }
                    }
                }
 
            }
        }
        .onAppear {
            if !valuesLoaded {
                inputArtist = album?.artist ?? ""
                inputTitle = album?.title ?? ""
                inputYear = album?.showYear ?? ""
                valuesLoaded = true
                selectedImage = album?.showCover
            }
        }
        .sheet(isPresented: $showPhotoLib) {
            ImagePicker(sourceType: .photoLibrary, selectedImage: $selectedImage)
        }
    }
    
    func saveBook(title: String, artist: String,  year: Int32) async {
        await dbContext.perform {
            album?.title = title
            album?.year = year
            album?.artist = artist
            album?.cover = selectedImage!.pngData()
            album?.thumbnail = selectedImage!.pngData()
            
            do {
                try dbContext.save()
                dismiss()
            } catch {
                print(error)
            }
        }
    }

}


struct ModifyAlbumView_Previews: PreviewProvider {
    static var previews: some View {
        ModifyAlbumView(album: nil)
            .environment(\.managedObjectContext, PersistenceController.preview.container.viewContext)
    }
}
