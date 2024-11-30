//
//  Album+ViewModel.swift
//  Album
//
//  Created by Rami Lake on 5/1/22.
//

import Foundation
import UIKit

extension Album {
    var showTitle: String {
        return title ?? "Undefined"
    }
    
    var showYear: String {
        return String(year)
    }
    
    var showArtist: String {
        return artist ?? "Undefined"
    }

    var showThumbnail: UIImage {
        if let data = thumbnail, let image = UIImage(data: data) {
            return image
        } else {
            return UIImage(named: "nopicture")!
        }
    }

    var showCover: UIImage {
        if let data = cover, let image = UIImage(data: data) {
            return image
        } else {
            return UIImage(named: "nopicture")!
        }
    }
}

