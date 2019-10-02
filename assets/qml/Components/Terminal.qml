/*
 * Copyright (c) 2018 Kaan-Sat <https://kaansat.com.mx/>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.4
import QtQuick.Controls.Universal 2.0

Item {
    //
    // Custom properties
    //
    property int scrollback: 100
    property bool autoScroll: true
    property alias text: _textDisplay.text
    property alias textContainer: _textDisplay

    //
    // Appends the given string to the text and scrolls
    // the view to the bottom
    //
    function append(str) {
        text += str
        if (autoScroll)
            textContainer.cursorPosition = textContainer.length
    }

    //
    // Clears the current buffer
    //
    function clear() {
        text = ""
    }

    //
    // Text display
    //
    TextArea {
        id: _textDisplay
        readOnly: true
        color: "#72d5a3"
        font.pixelSize: 12
        anchors.fill: parent
        font.family: app.monoFont
        textFormat: Text.PlainText
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        placeholderText: qsTr("No data received so far") + "..."

        onLineCountChanged: {
            if (lineCount > scrollback)
                remove(0, length / 2)
        }
    }
}
