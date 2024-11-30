//
//  ContentView.swift
//  Text
//
//  Created by Reinaldo Moraga on 2/3/22.
//

import SwiftUI

struct ContentView: View {
    
    let name = "Naldo"
    let total = 10323.47
    
    var formatter: NumberFormatter {
        let formatter = NumberFormatter()
        formatter.numberStyle = .currency
        return formatter
    }
    
    var body: some View {
        VStack(spacing: 20) {
            Text("Hello, \(name)")
                .fontWeight(.heavy)

            Text("This is a longer string than we've seen previously! It goes on for multiple lines.")
                .foregroundColor(.blue)
                .font(.title3)
                .bold()
                .multilineTextAlignment(.center)
                .padding()
            
            Text("The total is $\(total, specifier: "%.2f")")
                .italic()
            
            Text("The total is \(NSNumber(value: total), formatter: formatter)")
                .padding(10)
                .background(.mint)
                .foregroundColor(.white)
            
            Text( "Welcome to SwiftUI")
                .font(.custom("Espoir", size: 10))
            
        }
        .onAppear {
            for fontFamily in UIFont.familyNames {
                for fontName in UIFont.fontNames(forFamilyName: fontFamily) {
                print("\(fontName)")
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
