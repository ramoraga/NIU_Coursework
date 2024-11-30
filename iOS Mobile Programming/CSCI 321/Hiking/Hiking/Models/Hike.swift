//
//  Hike.swift
//  Hiking
//
//  Created by Reinaldo Moraga on 3/3/22.
//

import Foundation

struct Hike {
    let name: String
    let imageName: String
    let miles: Double
}

extension Hike {
    static func all() -> [Hike] {
        return [
            Hike(name: "Imaginary Trail", imageName: "hike1", miles: 6),
            Hike(name: "Mount Nowhere", imageName: "hike2", miles: 5.8),
            Hike(name: "Cheese Road", imageName: "hike3", miles: 4),
            Hike(name: "Phat Trail", imageName: "hike4", miles: 6.1),
        ]
    }
}
