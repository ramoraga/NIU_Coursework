//
//  ContentView.swift
//  Books
//
//  Created by Reinaldo Moraga on 2/22/22.
//

import SwiftUI

struct ContentView: View {
    
    let book = bookData
    
    var body: some View {
        
        // ScrollView for different sized screens
        ScrollView(showsIndicators: false) {
            VStack {
                
                // Inserting and displaying cover of textbook
                Image("cover")
                    .resizable()
                    .frame(width: 160, height: 200)
                    .cornerRadius(10)
                    .shadow(color: .gray, radius: 5, x: 5, y: 5)
                    .padding(15)
                
                // Diplays authors
                Text(book.authors)
                    .foregroundColor(.gray)
                
                // Displays book title
                Text(book.title)
                    .font(.title)
                    .bold()
                
                // Displays description of book
                Text(book.description)
                    .foregroundColor(.gray)
                    .padding(10)
                
                // Using ForEach to display each category of book and
                // an HStack to display categories horizontally
                HStack(spacing: 20) {
                    ForEach(book.categories, id: \.self) { category in
                        Text("\(category)")
                            .font(.subheadline)
                            .bold()
                            .padding(7)
                            .overlay(Capsule().stroke(lineWidth: 2))
                    }
                }
                // Displays divider line
                Divider()
                    .padding()
                
                // Declare and initialize bookPrize using a Number Formatter
                let bookPrice = String(format: "%.2f", book.price)
                
                // Displays buy button
                Text("Buy for $\(bookPrice)")
                    .foregroundColor(.white)
                    .font(.body)
                    .padding(12)
                    .background(Capsule())
                
                Spacer(minLength: 30)
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
