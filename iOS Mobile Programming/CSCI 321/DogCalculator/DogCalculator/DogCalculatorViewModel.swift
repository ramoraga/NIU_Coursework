//
//  DogCalculatorViewModel.swift
//  DogCalculator
//
//  Created by Reinaldo Moraga & Rami Lake on 3/8/22.
//

import Foundation

class DogCalculatorViewModel: ObservableObject {
    
    @Published var dogAgeText = ""
    @Published var humanAgeText = ""
    @Published var errorMessage = ""
    @Published var resultMessage = ""
    @Published var showAlert = false
    
    func compute() {
        
        // Convert user input string to a double
        // If input can't be converted to double, display error message
        guard let dogAge = Double(dogAgeText) else {
            errorMessage = "Please enter a valid age for your dog!"
            showAlert = true
            return
        }
        
        var humanAge: Double
        
        // Calculate dog age to human age using forumla below
        humanAge = (16 * log(Double(dogAge))) + 31
        humanAgeText = String(format: "%.f", humanAge)
        
        // Return string for output with human age
        resultMessage = "In human years, your dog is \(humanAgeText)!"
    }
}
