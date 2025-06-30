# 🎮 FPGA Up/Down Counter and VGA Test – CPHS Assignment 1

Implementation of an up/down counter with pattern detection and VGA output validation on FPGA.  
Developed for the course **Co-Projeto Hardware e Software (CPHS)** – **University of Coimbra**.

> 🧠 **Course:** CPHS  
> 🏫 **Institution:** Universidade de Coimbra – DEEC  
> 👨‍🎓 **Authors:** Gonçalo Bastos eusoudebastos@gmail.com, Leonardo Cordeiro leoleocordeiro@gmail.com 
> 📅 **Submission:** January 2024

---

## 🧩 Assignment Overview

The assignment is divided into two parts:

### 🔢 **Part 1 – Counter & Pattern Detection**

- **Up/Down Counter** controlled via `SW[0]`
- Output shown on:
  - LEDs
  - 4-digit **Hexadecimal** or **Decimal** 7-segment display
- **Pattern detection** ("1010" on `LED[3..0]`)
  - If detected, `LEDG[0]` lights up
- **PIO + NIOS II Simulation**
  - Software sends alternating values (10 and 0) to simulate detection
---

### 🎨 **Part 2 – VGA Output Test**

- Platform Designer setup with:
  - `video_pll_0`, `vga_controller`, `rgb_resampler`, `scaler`, etc.
- Successfully tested using **Video Test Pattern Generator**
- Displayed output via VGA cable to monitor

---

## 🧪 Technologies Used

- **Quartus II** (Intel FPGA)
- **VHDL**
- **NIOS II Softcore Processor**
- **Platform Designer**
- **VGA driver components**

---

## 📂 Project Structure

- `Assignment_1_Report.pdf`: Technical report with figures and design  
- `src/`: VHDL and Platform Designer source files  
- `software/`: C code for NIOS II detection test  
- `media/`: FPGA demonstration videos  

---

## 📌 To Run

1. Open Quartus project in `src/`
2. Program FPGA with `.sof` file
3. Run C code on NIOS II through Eclipse
4. Observe LED behavior / VGA screen
