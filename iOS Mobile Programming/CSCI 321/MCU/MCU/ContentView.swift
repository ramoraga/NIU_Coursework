//
//  ContentView.swift
//  MCU
//
//  Created by Reinaldo Moraga on 4/5/22.
//

import SwiftUI

struct ContentView: View {
    
    @StateObject private var characterListViewModel: CharacterListViewModel
    
    init() {
        _characterListViewModel = StateObject(wrappedValue: CharacterListViewModel())
    }
    
    var body: some View {
        NavigationView {
            
            List {
                ForEach(characterListViewModel.characters, id: \.name) {
                    characterVM in
                    NavigationLink(destination: CharacterDetailView(character: characterVM)) { CharacterCell(character: characterVM) }
                }
            }
            .listStyle(.plain)
            .task {
                await characterListViewModel.getCharacters()
            }
            .navigationTitle("MCU Characters")
            .navigationBarTitleDisplayMode(.inline)
        }
        .navigationViewStyle(.stack)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
