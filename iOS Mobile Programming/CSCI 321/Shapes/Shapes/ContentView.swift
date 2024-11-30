//
//  ContentView.swift
//  Shapes
//
//  Created by Reinaldo Moraga on 2/10/22.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack(spacing: 20) {
            Capsule(style: .continuous)
                .frame(width: 200, height: 100)
                .foregroundColor(.mint)
            
            Circle()
                .frame(width: 200, height: 100)
                .foregroundColor(.green)
            
            Ellipse()
                .frame(width: 150, height: 100)
                .foregroundColor(.cyan)
            
            HStack(spacing: 30) {
                Rectangle()
                    .frame(width: 100, height: 100)
                    .foregroundColor(.brown)
                
                RoundedRectangle(cornerRadius: 20)
                    .frame(width: 100, height: 100)
                    .foregroundColor(.purple)
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
