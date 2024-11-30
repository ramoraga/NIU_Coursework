//
//  ContentView.swift
//  Color
//
//  Created by Reinaldo Moraga on 2/8/22.
//

import SwiftUI

struct ContentView: View {
    let gradient = Gradient(colors: [.green, .white, .blue])
    
    var body: some View {
        
        RadialGradient(gradient: gradient, center: .center, startRadius: 0.0, endRadius: 100.0)
            .frame(width: 200, height: 200)
            .cornerRadius(20)
        
        VStack {
            Spacer()
            
            ZStack {
                
                Text("Hello")
                    .font(.largeTitle)
                    .bold()
                
                
            Color(red: 62/255, green: 180/255, blue: 137/255)
                .cornerRadius(20)
                .opacity(0.6)
                .frame(width: 100, height: 100)
                .shadow(radius: 10)
            }
     
            Spacer()

            Color(white: 0.9, opacity: 1)
                .frame(width: 200, height: 200)
            Spacer()
            
            
        }
        
        
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
