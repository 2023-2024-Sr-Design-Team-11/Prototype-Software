/**
 * @file DeliveryDriver.h
 * @author Jake Armstrong
 * @version 0.1
 * 
 * @section description
 * The interface for which the final drug delivery mechanism code must implement.
 * The DeliveryDriver will be in a task that is periodically called.
 * 
 * @section ECE implementation details
 * We will call the functions in this library to interface with the ME team's driver for their actuator.
*/

#ifndef DeliveryDriver_defined
#define DeliveryDriver_defined

/**
 * @name setup
 * @returns void
 * @section Description
 * One-time call for setting up your driver.
 * 
 * @subsection ECE Implementation Notes
 * This function should be called in the **main.cpp** `void setup()` function.
 * 
 * @section Usage
 *      // File: YourDriver.c
 *      #include DeliveryDriver.h
 *      void setup() {
 *          // Your code for setting up your driver.
 *      }
*/
void setup();

/**
 * @name loop
 * @returns void
 * @section Description
 * Periodic call 
 * 
 * @subsection ECE Implementation Notes
 * This function should be called in the medical delivery task.
 * 
 * @section Usage
 *      // File: YourDriver.c
 *      #include DeliveryDriver.h
 *      void loop() {
 *          // Your code for setting up your driver.
 *      }
*/
void loop();


#endif