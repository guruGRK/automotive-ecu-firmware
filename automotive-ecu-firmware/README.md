# Automotive ECU Firmware (Register-Level STM32 Style)

## Overview

This project demonstrates the implementation of an **Automotive ECU (Electronic Control Unit) firmware** using **custom register-mapped drivers**, inspired by STM32 architecture.

The firmware is designed with a **layered architecture**, mimicking real embedded systems used in industry.

> Focus: Pure firmware design using register-level programming (no HAL, no libraries)

---

## Architecture

```text
Application Layer (ECU Logic)
        ↓
Driver Layer (GPIO, ADC, RCC)
        ↓
MCAL (Register Mapping)
        ↓
Hardware (STM32 Concept)
```

---

## Project Structure

```bash
automotive-ecu-firmware/
│
├── app/
│   ├── ecu.c
│   └── ecu.h
│
├── drivers/
│   ├── gpio.c
│   ├── gpio.h
│   ├── adc.c
│   ├── adc.h
│   ├── rcc.c
│   └── rcc.h
│
├── mcal/
│   └── stm32f4.h
│
├── bsp/
│   └── board.h
│
├── main.c
└── README.md
```

---

## Features

* ✅ Register-level GPIO control (MODER, ODR)
* ✅ ADC sensor reading (polling-based)
* ✅ RCC-based peripheral clock control
* ✅ Layered firmware architecture (MCAL, Drivers, BSP, Application)
* ✅ State machine-based ECU logic
* ✅ Fault detection mechanism

---

## System Behavior

The ECU monitors a simulated temperature sensor and controls outputs accordingly.

### Flow

```text
ADC (Temperature Sensor)
        ↓
ECU Logic (Decision Making)
        ↓
GPIO (Fan / Buzzer Control)
```

---

## ECU State Machine

| State    | Condition                | Action              |
| -------- | ------------------------ | ------------------- |
| NORMAL   | Temperature ≤ 90         | Fan OFF, Buzzer OFF |
| OVERHEAT | Temperature > 90         | Fan ON, Buzzer ON   |
| FAULT    | Temp < -40 or Temp > 150 | Fan OFF, Buzzer ON  |

---

## Key Implementation Details

### 🔹 Register Mapping (MCAL)

Custom structs map hardware registers directly:

* GPIO → MODER, ODR
* RCC → AHB1ENR, APB2ENR
* ADC → SR, CR2, SQR3, DR

---

### 🔹 GPIO Driver

* Configures pin mode using MODER register
* Controls output using ODR register

---

### 🔹 ADC Driver

* Enables ADC via RCC
* Selects channel using SQR3
* Starts conversion using CR2
* Polls EOC flag from SR
* Reads result from DR

---

### 🔹 RCC Driver

* Enables peripheral clocks (GPIO, ADC)
* Required before accessing hardware registers

---

### 🔹 ECU Logic

* Implements a **state machine**
* Reads temperature via ADC
* Controls fan and buzzer via GPIO

---

## Key Learning Outcomes

* Memory-mapped register programming
* Bit manipulation and masking
* Peripheral clock control (RCC)
* ADC interfacing (polling method)
* Layered firmware design
* State machine implementation
* Embedded C driver development

---

## How to Build

This project is written in standard Embedded C and can be compiled using:

* Keil uVision
* STM32CubeIDE
* GCC (arm-none-eabi)

---

## Note

This project focuses on **firmware design and architecture**, demonstrating how embedded systems are built at a low level using direct register access.

---

## Acknowledgment

Inspired by STM32 register-level programming concepts and real-world embedded firmware design practices.

---
