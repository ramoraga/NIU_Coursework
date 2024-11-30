//
//  CharacterDetailView.swift
//  MCU
//
//  Created by Reinaldo Moraga on 4/7/22.
//

import SwiftUI

struct CharacterDetailView: View {
    
    var character: CharacterViewModel
    
    var body: some View {
        VStack(spacing: 16) {
            Text(character.name)
                .font(.largeTitle)
                .fontWeight(.heavy)
                .multilineTextAlignment(.center)
            
            AsyncImage(url: URL(string: character.url)) {
                image in
                image.resizable()
                    .scaledToFit()
                    .cornerRadius(16)
            } placeholder: {
                ProgressView()
            }
            .padding(.horizontal)
            
            Text("Real Name")
                .font(.title3)
                .fontWeight(.semibold)
            
            Text(character.realName)
            
            Text("Affiliation")
                .font(.title3)
                .fontWeight(.semibold)
            
            Text(character.affiliation)
            
            Spacer()
        }
    }
}

struct CharacterDetailView_Previews: PreviewProvider {
    static var previews: some View {
        CharacterDetailView(character: CharacterViewModel.default)
    }
}
