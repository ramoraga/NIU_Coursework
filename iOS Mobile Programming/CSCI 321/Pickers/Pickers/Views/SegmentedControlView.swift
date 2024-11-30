//
//  SegmentedControlView.swift
//  Pickers
//
//  Created by Reinaldo Moraga on 2/22/22.
//

import SwiftUI

enum Flavor: String, CaseIterable, Identifiable {
    case vanilla
    case strawberry
    case chocolate
    
    var id: String { self.rawValue }
}

struct SegmentedControlView: View {
    
    @State private var selectedFlavor = Flavor.vanilla
    
    var body: some View {
        
        VStack {
            Text("Choose a Flavor")
            
            Picker("Flavor", selection: $selectedFlavor) {
               /* Text("Vanilla").tag(Flavor.vanilla)
                Text("Strawberry").tag(Flavor.strawberry)
                Text("Chocolate").tag(Flavor.chocolate)*/
                
                ForEach(Flavor.allCases) { flavor in
                    Text(flavor.rawValue.capitalized)
                        .tag(flavor)
                }
            }
            .pickerStyle(SegmentedPickerStyle())
            .padding(.horizontal)
            
            Text("You selected \(selectedFlavor.rawValue.capitalized)")
                .padding()
        }
    }
}

struct SegmentedControlView_Previews: PreviewProvider {
    static var previews: some View {
        SegmentedControlView()
    }
}
