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

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QChar>
#include <QString>
#include <QByteArray>

#include <cmath>

/**
 * Defines what the last character of a packet generated by the
 * CanSAT should be.
 *
 * This is used to determine when we have received a full packet from the
 * CanSat.
 */
static const QChar EOT_PRIMARY = QChar('\n');

/**
 * Defines the next-to-last character of each packet.
 * Using two characters to separate packets gives us the following benefits:
 *   - If we need to process more than one packet, we can do it by creating
 *     an array of packets (using @c EOT_CHAR)
 *   - We can detect and manage incomplete packets (using @c EOT_CHAR_SECONDARY)
 */
static const QChar EOT_SECONDARY = QChar('\r');

/**
 * Define data separator character
 */
static const QChar DATA_SEPARATOR = QChar(',');

/**
 * Defines the characters that each packet generated by the CanSat should
 * begin with. This information is used as an additional packet
 * validation method.
 */
static const QByteArray HEADER_CODE = "KAANSATQRO";

/**
 * Set maximum buffer size of 10 Kilobytes
 */
static const int MAX_BUFFER_SIZE = 10 * 1024;

/**
 * Packet validation options
 */
static const bool ENABLE_CRC32 = false;
static const bool ENABLE_PACKET_CHECK = true;

/**
 * Rounds the given @a number to two decimal places
 */
static inline double RoundDbl(const double n) {
    return floorl(n * 100.0) / 100.0;
}

#endif
