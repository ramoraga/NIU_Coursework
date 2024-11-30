//
//  ViewController.swift
//  TinyToyTank
//
//  Created by Reinaldo Moraga on 4/21/22.
//

import UIKit
import RealityKit

var tankAnchor: TinyToyTank._TinyToyTank?

class ViewController: UIViewController {
    
    @IBOutlet weak var tankRightPressed: UIButton!
    @IBOutlet var arView: ARView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Load the "Box" scene from the "Experience" Reality File
        tankAnchor = try! TinyToyTank.load_TinyToyTank()
        
        // Add the box anchor to the scene
        arView.scene.anchors.append(tankAnchor!)
    }
}
