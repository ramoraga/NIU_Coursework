//
//  ContentView.swift
//  ForEach
//
//  Created by Reinaldo Moraga on 2/15/22.
//

import SwiftUI

struct SimpleGameResult: Identifiable {
    let id = UUID()
    let score: Int
}

struct ContentView: View {
    
    let results = [
        SimpleGameResult(score: 8),
        SimpleGameResult(score: 5),
        SimpleGameResult(score: 10),
        SimpleGameResult(score: 8)
    ]
    
    var body: some View {
        
        //let colors: [Color] = [.red, .green, .blue, .mint, .purple]
                
        VStack(alignment: .center) {
            
            ForEach(results) { result in
                Text("Result: \(result.score)")
            }
            
            
            
           
           /* ForEach(colors, id: \.self) { color in
                Text(color.description.capitalized)
                    .frame(width: 75, height: 75)
                    .background(color)
            }*/
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
