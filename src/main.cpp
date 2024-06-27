#include <Arduino.h>
#include <RenogyChargeController.h>

RenogyChargeController charge_controller(Serial1);

void setup()
{
	Serial2.begin(115200);
	Serial2.println("Started!");

	charge_controller.begin();
}

void loop()
{
	// charge_controller.update();
	charge_controller.read_data_registers();
	charge_controller.read_info_registers();

	Serial2.println("Battery voltage: " + String(charge_controller.renogy_data.battery_voltage));
	Serial2.println("Battery charge level: " + String(charge_controller.renogy_data.battery_soc) + "%");
	Serial2.println("Panel wattage: " + String(charge_controller.renogy_data.solar_panel_watts));
	Serial2.println("controller_temperatureF=" + String(charge_controller.renogy_data.controller_temperatureF));
	Serial2.println("battery_temperatureF=" + String(charge_controller.renogy_data.battery_temperatureF));
	Serial2.println("---");

	// turn the load on for 10 seconds
	// renogy_control_load(1)
	// delay(10000);
	// renogy_control_load(0)

	delay(1000);
}