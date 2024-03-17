<h1>Board Build Variants</h1>

Below you will find a list of build which can be configured and should compile without any problems

<hr>
<a name="espressif_2.0.13_esp32_esp32"></a><b>Core:</b> <a h_ref="https://github.com/espressif/arduino-esp32">ESP32 Arduino</a><br />
<b>Version:</b> 2.0.13<br />
<b>Board:</b> ESP32 Dev Module<br />
<br />
<b>Program storage space:</b> 830197 bytes<br />
<b>Dynamic memory:</b> 45596 bytes<br />
<br />
<b>JTAG Adapter:</b> Disabled<br />
<b>PSRAM:</b> Enabled<br />
<b>Partition Scheme:</b> No OTA (2MB APP/2MB SPIFFS)<br />
<b>CPU Frequency:</b> 240MHz (WiFi/BT)<br />
<b>Flash Mode:</b> QIO<br />
<b>Flash Frequency:</b> 80MHz<br />
<b>Flash Size:</b> 4MB (32Mb)<br />
<b>Upload Speed:</b> 921600<br />
<b>Arduino Runs On:</b> Core 1<br />
<b>Events Run On:</b> Core 1<br />
<b>Core Debug Level:</b> None<br />
<b>Erase All Flash Before Sketch Upload:</b> Disabled<br />
<br />
<b>Used libraries:</b><br />
<table>
    <tr>
        <td>Name</td>
        <td>Version</td>
        <td>Url</td>
        <td>Git</td>
        <td>Core library</td>
    </tr>
    <tr>
        <td>ML SynthTools</td>
        <td>1.2.0</td>
        <td>https://github.com/marcel-licence/ML_SynthTools</td>
        <td>https://github.com/marcel-licence/ML_SynthTools.git</td>
        <td>False</td>
    </tr>
    <tr>
        <td>WiFi</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>Wire</td>
        <td>2.0.0</td>
        <td>http://arduino.cc/en/Reference/Wire</td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>FS</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>LittleFS</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>SD_MMC</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>Adafruit GFX Library</td>
        <td>1.10.10</td>
        <td>https://github.com/adafruit/Adafruit-GFX-Library</td>
        <td></td>
        <td>False</td>
    </tr>
    <tr>
        <td>Adafruit SSD1306</td>
        <td>2.4.5</td>
        <td>https://github.com/adafruit/Adafruit_SSD1306</td>
        <td></td>
        <td>False</td>
    </tr>
    <tr>
        <td>SPI</td>
        <td>2.0.0</td>
        <td>http://arduino.cc/en/Reference/SPI</td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>Adafruit BusIO</td>
        <td>1.14.1</td>
        <td>https://github.com/adafruit/Adafruit_BusIO</td>
        <td>https://github.com/adafruit/Adafruit_BusIO</td>
        <td>False</td>
    </tr>
</table><hr>
<a name="esp8266_esp8266_d1_mini"></a><b>Core:</b> <a h_ref="https://github.com/esp8266/Arduino">ESP8266 Boards </a><br />
<b>Version:</b> 3.1.2<br />
<b>Board:</b> LOLIN(WEMOS) D1 R2 & mini<br />
<br />
<br />
<b>CPU Frequency:</b> 160 MHz<br />
<b>VTables:</b> Flash<br />
<b>C++ Exceptions:</b> Disabled (new aborts on oom)<br />
<b>Stack Protection:</b> Disabled<br />
<b>SSL Support:</b> All SSL ciphers (most compatible)<br />
<b>MMU:</b> 32KB cache + 32KB IRAM (balanced)<br />
<b>Non-32-Bit Access:</b> Use pgm_read macros for IRAM/PROGMEM<br />
<b>Flash Size:</b> 4MB (FS:2MB OTA:~1019KB)<br />
<b>lwIP Variant:</b> v2 Lower Memory<br />
<b>Debug port:</b> Disabled<br />
<b>Debug Level:</b> None<br />
<b>Erase Flash:</b> Only Sketch<br />
<b>Upload Speed:</b> 921600<br />
<br />
<b>Used libraries:</b><br />
<table>
    <tr>
        <td>Name</td>
        <td>Version</td>
        <td>Url</td>
        <td>Git</td>
        <td>Core library</td>
    </tr>
    <tr>
        <td>ML SynthTools</td>
        <td>1.2.0</td>
        <td>https://github.com/marcel-licence/ML_SynthTools</td>
        <td>https://github.com/marcel-licence/ML_SynthTools.git</td>
        <td>False</td>
    </tr>
    <tr>
        <td>ESP8266WiFi</td>
        <td>1.0</td>
        <td></td>
        <td></td>
        <td>True</td>
    </tr>
    <tr>
        <td>I2S</td>
        <td>1.0</td>
        <td>http://www.arduino.cc/en/Reference/I2S</td>
        <td></td>
        <td>True</td>
    </tr>
    <tr>
        <td>LittleFS</td>
        <td>0.1.0</td>
        <td>https://github.com/esp8266/Arduino/libraries/LittleFS</td>
        <td></td>
        <td>True</td>
    </tr>
</table><hr>
<a name="rp2040_rp2040_rpipico"></a><b>Core:</b> <a h_ref="https://github.com/earlephilhower/arduino-pico">Raspberry Pi RP2040 Boards</a><br />
<b>Version:</b> 3.2.0<br />
<b>Board:</b> Raspberry Pi Pico<br />
<br />
<b>Program storage space:</b> 112628 bytes<br />
<b>Dynamic memory:</b> 193052 bytes<br />
<br />
<b>Flash Size:</b> 2MB (Sketch: 1MB, FS: 1MB)<br />
<b>CPU Speed:</b> 133 MHz<br />
<b>Optimize:</b> Optimize Even More (-O3)<br />
<b>RTTI:</b> Disabled<br />
<b>Stack Protector:</b> Disabled<br />
<b>C++ Exceptions:</b> Disabled<br />
<b>Debug Port:</b> Disabled<br />
<b>Debug Level:</b> None<br />
<b>USB Stack:</b> Adafruit TinyUSB<br />
<b>IP/Bluetooth Stack:</b> IPv4 Only<br />
<b>Upload Method:</b> Default (UF2)<br />
<br />
<b>Used libraries:</b><br />
<table>
    <tr>
        <td>Name</td>
        <td>Version</td>
        <td>Url</td>
        <td>Git</td>
        <td>Core library</td>
    </tr>
    <tr>
        <td>ML SynthTools</td>
        <td>1.2.0</td>
        <td>https://github.com/marcel-licence/ML_SynthTools</td>
        <td>https://github.com/marcel-licence/ML_SynthTools.git</td>
        <td>False</td>
    </tr>
    <tr>
        <td>I2S</td>
        <td>2.0</td>
        <td>http://www.arduino.cc/en/Reference/I2S</td>
        <td></td>
        <td>True</td>
    </tr>
    <tr>
        <td>AudioBufferManager</td>
        <td>1.0.0</td>
        <td>https://github.com/earlephilhower/arduino-pico</td>
        <td></td>
        <td>True</td>
    </tr>
    <tr>
        <td>LittleFS</td>
        <td>0.1.0</td>
        <td>https://github.com/earlephilhower/arduino-pico</td>
        <td></td>
        <td>True</td>
    </tr>
    <tr>
        <td>Adafruit TinyUSB Library</td>
        <td>1.14.4</td>
        <td>https://github.com/adafruit/Adafruit_TinyUSB_Arduino</td>
        <td></td>
        <td>False</td>
    </tr>
</table><hr>
<a name="espressif_2.0.13_esp32_lolin_s2_mini"></a><b>Core:</b> <a h_ref="https://github.com/espressif/arduino-esp32">ESP32 Arduino</a><br />
<b>Version:</b> 2.0.13<br />
<b>Board:</b> LOLIN S2 Mini<br />
<br />
<b>Program storage space:</b> 737242 bytes<br />
<b>Dynamic memory:</b> 51308 bytes<br />
<br />
<b>USB CDC On Boot:</b> Enabled<br />
<b>USB Firmware MSC On Boot:</b> Disabled<br />
<b>USB DFU On Boot:</b> Disabled<br />
<b>Partition Scheme:</b> Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)<br />
<b>Core Debug Level:</b> None<br />
<b>Erase All Flash Before Sketch Upload:</b> Disabled<br />
<br />
<b>Used libraries:</b><br />
<table>
    <tr>
        <td>Name</td>
        <td>Version</td>
        <td>Url</td>
        <td>Git</td>
        <td>Core library</td>
    </tr>
    <tr>
        <td>ML SynthTools</td>
        <td>1.2.0</td>
        <td>https://github.com/marcel-licence/ML_SynthTools</td>
        <td>https://github.com/marcel-licence/ML_SynthTools.git</td>
        <td>False</td>
    </tr>
    <tr>
        <td>WiFi</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>FS</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>LittleFS</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>SD_MMC</td>
        <td>2.0.0</td>
        <td></td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>Wire</td>
        <td>2.0.0</td>
        <td>http://arduino.cc/en/Reference/Wire</td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>Adafruit GFX Library</td>
        <td>1.10.10</td>
        <td>https://github.com/adafruit/Adafruit-GFX-Library</td>
        <td></td>
        <td>False</td>
    </tr>
    <tr>
        <td>Adafruit SSD1306</td>
        <td>2.4.5</td>
        <td>https://github.com/adafruit/Adafruit_SSD1306</td>
        <td></td>
        <td>False</td>
    </tr>
    <tr>
        <td>SPI</td>
        <td>2.0.0</td>
        <td>http://arduino.cc/en/Reference/SPI</td>
        <td>https://github.com/espressif/arduino-esp32.git</td>
        <td>True</td>
    </tr>
    <tr>
        <td>Adafruit BusIO</td>
        <td>1.14.1</td>
        <td>https://github.com/adafruit/Adafruit_BusIO</td>
        <td>https://github.com/adafruit/Adafruit_BusIO</td>
        <td>False</td>
    </tr>
</table>