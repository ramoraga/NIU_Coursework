//
//  BookModel.swift
//  Books
//
//  Created by Reinaldo Moraga on 2/22/22.
//

import Foundation
import SwiftUI

// Create model struct Book
struct Book: Identifiable {
    let id = UUID()
    var image: String
    var authors: String
    var title: String
    var description: String
    var categories = [String]()
    var price: Double
}
