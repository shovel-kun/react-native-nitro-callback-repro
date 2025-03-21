package com.testview

import android.graphics.Color
import android.util.Log
import android.view.View
import androidx.annotation.Keep
import com.facebook.proguard.annotations.DoNotStrip
import com.facebook.react.uimanager.ThemedReactContext
import com.margelo.nitro.testview.HybridTestViewSpec

@Keep
@DoNotStrip
class HybridTestView(val context: ThemedReactContext): HybridTestViewSpec() {
    // View
    override val view: View = View(context)

    // Props
    private var _isRed = false
    override var isRed: Boolean
        get() = _isRed
        set(value) {
            Log.i("isRed", "isRed of value: ${value}")
            Log.i("isRed", "onColorChange of value: ${onColorChange.hashCode()}")
            Log.i("isRed", "Invoking")
            onColorChange.invoke()
            Log.i("isRed", "Done invoking")
            _isRed = value
            view.setBackgroundColor(
                if (value) Color.RED
                else Color.BLACK
            )
        }

    // Callbacks
    override var onColorChange: () -> Unit = {}
        set(value) {
            Log.d("onColorChange", "onColorChange of value: ${value.hashCode()}")
            field = value
        }
}
