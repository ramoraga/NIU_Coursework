//
//  WebService.swift
//  MCU
//
//  Created by Reinaldo Moraga on 4/5/22.
//

import Foundation

class WebService {
    
    func fetchCharacters(url: URL?) async throws -> [MCUCharacter] {
        
        guard let url = url else {
            return []
        }
        
        let (data, _) = try await URLSession.shared.data(from: url)
        
        let characters = try? JSONDecoder().decode([MCUCharacter].self, from: data)
        
        return characters ?? []
    }
}
