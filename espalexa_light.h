#include "esphome.h"
#include <Espalexa.h>

namespace esphome {
namespace espalexa_light {

class EspalexaLightComponent : public Component {
 public:
  Espalexa espalexa;
  EspalexaDevice* device1;
  EspalexaDevice* device2;
  EspalexaDevice* device3;
  EspalexaDevice* device4;

  void setup() override {
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(12, OUTPUT);

    espalexa.begin();
    device1 = new EspalexaDevice("Pump 1", [](EspalexaDevice* d) { digitalWrite(5, d->getValue()); }, EspalexaDeviceType::onoff);
    device2 = new EspalexaDevice("Pump 2", [](EspalexaDevice* d) { digitalWrite(4, d->getValue()); }, EspalexaDeviceType::onoff);
    device3 = new EspalexaDevice("Pump 3", [](EspalexaDevice* d) { digitalWrite(14, d->getValue()); }, EspalexaDeviceType::onoff);
    device4 = new EspalexaDevice("Pump 4", [](EspalexaDevice* d) { digitalWrite(12, d->getValue()); }, EspalexaDeviceType::onoff);

    espalexa.addDevice(device1);
    espalexa.addDevice(device2);
    espalexa.addDevice(device3);
    espalexa.addDevice(device4);
  }

  void loop() override {
    espalexa.loop();
  }
};

}  // namespace espalexa_light
}  // namespace esphome
