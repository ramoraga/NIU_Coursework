//
//  CharacterListViewModel.swift
//  MCU
//
//  Created by Reinaldo Moraga on 4/5/22.
//

import Foundation

@MainActor
class CharacterListViewModel: ObservableObject {
    
    @Published var characters: [CharacterViewModel] = []
    
    func getCharacters() async {
        
        do {
            var characters = try await WebService().fetchCharacters(url: Constants.Urls.charactersUrl)
            characters.sort {
                $0.name < $1.name
            }
            self.characters = characters.map(CharacterViewModel.init)
        } catch {
            print(error)
        }
        
    }
}

struct CharacterViewModel {
    fileprivate var character: MCUCharacter
    
    var name: String {
        return character.name
    }
    
    var realName: String {
        return character.realName
    }
    
    var affiliation: String {
        return character.affiliation
    }
    
    var url: String {
        return character.url
    }
    
    static var `default`: CharacterViewModel {
        let character = MCUCharacter(name: "Captain America", realName: "Steve Rogers", affiliation: "Avengers", url: "https://www.prismnet.com/~mcmahon/CS321/Images/Marvel/captain_america-300.jpg")
        return CharacterViewModel(character: character)
    }
}
