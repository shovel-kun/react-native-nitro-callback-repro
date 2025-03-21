import Foundation
import UIKit

class HybridTestView : HybridTestViewSpec {
  // UIView
  var view: UIView = UIView()

  // Props
  var isRed: Bool = false {
    didSet {
      view.backgroundColor = isRed ? .red : .black
    }
  }
}
