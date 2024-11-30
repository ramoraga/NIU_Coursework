//
//  MCUCharacter.swift
//  MCU
//
//  Created by Reinaldo Moraga on 4/5/22.
//

import Foundation

struct MCUCharacter: Decodable {
    var name = ""
    var realName = ""
    var affiliation = ""
    var url = ""
    
    private enum CodingKeys: String, CodingKey {
        case name = "Name"
        case realName = "Real Name"
        case affiliation = "Affiliation"
        case url = "URL"
    }
}
