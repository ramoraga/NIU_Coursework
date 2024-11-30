import UIKit

struct Place: Decodable {
    var name: String
    var latitude: Double
    var longitude: Double
    var visited: Bool
}

let xml = """
<?xml version= "1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<array>
    <dict>
        <key>name</key>
        <string>San Jose, Costa Rica</string>
        <key>latitude</key>
        <real>9.56</real>
        <key>longitude</key>
        <real>84.5</real>
        <key>visited</key>
        <true/>
    </dict>
    <dict>
        <key>name</key>
        <string>San Juan, Puerto Rico</string>
        <key>latitude</key>
        <real>18.24</real>
        <key>longitude</key>
        <real>21.9</real>
        <key>visited</key>
        <false/>
    </dict>
    <dict>
        <key>name</key>
        <string>Mexico City, Mexico</string>
        <key>latitude</key>
        <real>39.56</real>
        <key>longitude</key>
        <real>99.5</real>
        <key>visited</key>
        <true/>
    </dict>
</array>
</plist>
""".data (using: .utf8)!

let array = try! PropertyListDecoder().decode([Place].self, from: xml)

print(array)
print(array[0])
print(array[0].name)
print(array[0].visited)

