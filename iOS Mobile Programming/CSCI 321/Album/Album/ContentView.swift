//
//  ContentView.swift
//  Album
//
//  Created by Rami Lake on 4/29/22.
//

import SwiftUI
import CoreData

struct ContentView: View {
    @Environment(\.managedObjectContext) private var dbContext

    @FetchRequest(
        sortDescriptors: [SortDescriptor(\Album.title, order:.forward)], predicate: nil, animation: .default)
    private var listOfAlbums: FetchedResults<Album>

    var body: some View {
        NavigationView {
            List {
                ForEach(listOfAlbums) { album in
                    NavigationLink(destination: ModifyAlbumView(album: album), label: {
                        RowAlbum(album: album).id(UUID())
                    })
                } //: End of ForEach
                .onDelete(perform: { indexes in
                    Task(priority: .high) {
                        await deleteBook(indexes: indexes)
                    }
                })
            } //: End of list
            .navigationTitle("Albums")
            .navigationBarTitleDisplayMode(.inline)
            .toolbar {
                
//                ToolbarItem (placement: .navigationBarLeading) {
//                    Menu("Sort")
//
//                }
                
                ToolbarItem(placement:.navigationBarTrailing) {
                    NavigationLink(destination: InsertAlbumView(), label: {Image(systemName: "plus")})
                }
            }
        } //: End NavigationView
        .navigationViewStyle(.stack)
    } //: End of Body

    
    func deleteBook(indexes: IndexSet) async {
        await dbContext.perform {
            for index in indexes {
                dbContext.delete(listOfAlbums[index])
            }
            
            do {
                try dbContext.save()
            } catch {
                print(error)
            }
        }
    }
} //: End of ContentView

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView().environment(\.managedObjectContext, PersistenceController.preview.container.viewContext)
    }
}
