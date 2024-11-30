//
//  RowAlbum.swift
//  Album
//
//  Created by Rami Lake on 4/29/22.
//

import SwiftUI

struct RowAlbum: View {
    
    let album: Album
    
    var body: some View {
        HStack (alignment: .top) {
            Image(uiImage: album.showCover)
                .resizable()
                .scaledToFit()
                .frame(width: 80, height: 100)
                .cornerRadius(10)
            
            VStack(alignment: .leading, spacing: 2) {
                Text(album.showTitle)
                    .bold()
                Text(album.showArtist)
                    .foregroundColor(album.artist != nil ? .black : .gray)
                
                Text(album.showYear)
                    .font(.caption)
            }
            .padding(.top, 5)

            Spacer()
        }
    }
}

struct RowAlbum_Previews: PreviewProvider {
    
    static let viewContext = PersistenceController.preview.container.viewContext
    
    static var album: Album {
        let album = Album(context: viewContext)
        album.title = "Some Book"
        album.artist = nil
        album.year = 2021
        
        return album
    }
    
    static var previews: some View {
        RowAlbum(album: album)
            .previewLayout(.sizeThatFits)
    }
}
