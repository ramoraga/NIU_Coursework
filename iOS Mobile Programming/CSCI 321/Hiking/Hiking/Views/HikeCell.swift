//
//  HikeCell.swift
//  Hiking
//
//  Created by Reinaldo Moraga on 3/3/22.
//

import SwiftUI

struct HikeCell: View {
    let hike: Hike
    
    var body: some View {
        HStack {
            Image(hike.imageName)
                .resizable()
                .frame(width: 150, height: 100)
                .cornerRadius(16)
            VStack(alignment: .leading) {
                Text(hike.name)
                    .font(.title2)
                    .bold()
                
                Text("\(String(format: "%.1f", hike.miles)) miles")
                    .foregroundColor(.gray)
            }
        }
    }
}

struct HikeCell_Previews: PreviewProvider {
    static var previews: some View {
        HikeCell(hike: Hike.all()[0])
            .previewLayout(.sizeThatFits)
    }
}
