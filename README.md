# UCF Robotic Hand Design Project

Written by Junyang. I created this repository as an **organized copy of the original ORCA Hand design files** for the UCF robotic hand project. So far, I have collected, reviewed, and sorted the files into a more convenient structure. **I have not yet redesigned the hardware.**

My next major objective is to **replace the original ORCA Hand actuators with Dynamixel AX-18A servos**. The AX-18A conversion is **planned, not implemented yet**; the current models should not be assumed to fit AX-18A motors.

## Official ORCA Hand resources

- **Official website:** [ORCA Hand](https://www.orcahand.com/)
- **Fabrication and assembly tutorial:** [ORCA Hand full fabrication and assembly tutorial](https://youtu.be/TgIz7HiyaoU?si=PWOCt1g08h2LHRF3)

## Where to start

1. Open [`all files we corrently need/orca_v2/base_basic v2 version start with this folder/`](all%20files%20we%20corrently%20need/orca_v2/base_basic%20v2%20version%20start%20with%20this%20folder/).
2. Start with `Prints-1100_the hand 3d designed files.3mf` for the hand print plates and `SiliconeMolds-1100_the mold 3d file for silicon skin.3mf` for the silicone-skin molds.
3. For individual STL and STEP components, open `full v2 hand files/` inside the same directory.
4. Read `full v2 hand files/ASSEMBLY_ADDENDUM.md` alongside the [ORCA Hand fabrication and assembly tutorial](https://youtu.be/TgIz7HiyaoU?si=PWOCt1g08h2LHRF3). The addendum includes important corrections about PTFE tubes, thumb pins, carpal bearings, and spools. I have already organized the project BOM; see the final section for my completed reference workbook.
5. Treat the `touch` and `lite` directories as alternative designs, not as required components of the base build.

> **Important:** The current files include original Dynamixel and Feetech-specific parts. A filename containing `Dynamixel` does **not** establish compatibility with the AX-18A. Check dimensions, horn interface, fasteners, cable routing, torque, and power requirements before fabrication.

## Repository directory guide

The directory names below are reproduced **exactly as stored in this repository**, including their existing spelling, to make them easy to find.

### 1. `all files we corrently need/` — selected working files

This is the **working collection I selected and organized** for the project, containing the ORCA V2 designs I plan to study and modify.

- **`orca_v2/`** — selected V2 mechanical and electronic design files.
  - **`base_basic v2 version start with this folder/`** — **primary starting point** for the standard V2 hand. Contains two conveniently named `.3mf` print projects and the more complete `full v2 hand files/` directory.
    - **`full v2 hand files/`** — complete base-V2 hand component collection, including `Prints-1100.3mf`, `SiliconeMolds-1100.3mf`, left/right ZIP archives, assembly notes, and the folders below:
      - **`01_Fingers/`** — printable finger segments and thumb components (`.stl`); `step_files/` contains corresponding editable/importable CAD exchange models (`.step`).
      - **`02_Carpals/`** — palm/carpal structures, cores, gearing, and TPU carpal-skin components; `step_files/` contains available STEP models.
      - **`03_Wrist/`** — wrist structures, adapters, cable holders, and wrist gear, including separate original **Dynamixel** and **Feetech** configurations; `step_files/` contains STEP counterparts. **Relevant to the future AX-18A fit check.**
      - **`04_ForeArm/`** — forearm/tower structures, front/back shells, covers, fans, and mounting-related parts, with original motor-system-specific variants; `step_files/` contains available STEP models. **Likely a major AX-18A redesign area.**
      - **`05_Spools/`** — tendon-winding spool, ratchet, spool cover, and tensioner components, with STEP counterparts in `step_files/`. **Check mechanical coupling to replacement servos.**
      - **`06_CNC/`** — manufacturing models and PDF technical drawings for machined components, including the spool holder and Franka connector.
      - **`07_Molds/`** — mold STLs and `.3mf` projects for silicone skins, including compression molds and clips.
      - **`09_Skin/`** — finger and carpal skin STL geometry for flexible covers.
      - **`assembly-addendum/`** — photographs and diagrams referenced by `ASSEMBLY_ADDENDUM.md` (PTFE routing, bearings, pins, spool identification, and assembly tips).
      - **`ASSEMBLY_ADDENDUM.md`** — text instructions supplementing the original assembly video; review before assembly.
  - **`electronics_pcb files and random/`** — original ORCA motor-connector PCB documentation: `ORCA_Motor_Connectors_BOM.xls` and `ORCA_Motor_Connectors_Gerber/`.
    - **`ORCA_Motor_Connectors_Gerber/`** — PCB fabrication layers, drill files, and `How-to-order-PCB.txt`. **Connector compatibility must be rechecked for AX-18A.**
  - **`lite_a simple verson of v2 we dont need/`** — lightweight/simplified V2 variant files (`.stl`/`.step`). Retained for reference; **not the current build target**.
  - **`touch_the version that allows us to add touch sensor/`** — alternative V2 design intended to accommodate fingertip touch sensors. Contains `Prints-2100.3mf`, `SiliconeMolds-2100.3mf`, and left/right ZIP archives.
    - **`01_Fingers/`** — touch-variant finger STL parts; `step_files/` contains available STEP models.
    - **`02_Carpals/`** — touch-variant carpal STL parts; `step_files/` contains STEP models.
    - **`09_OldPrintBeds/`** — earlier touch-variant `.3mf` print-bed projects; use the main `Prints-2100.3mf` as the current touch starting point instead.

### 2. `full files check it out if have time/` — complete upstream reference archive

I kept this folder as a broader archive of original ORCA project material. It is **reference material**, not my preferred starting point for the UCF build.

- **`README.md`** — upstream ORCA file-set overview, including variants, print projects, and scripts.
- **`assets/`** — upstream documentation image assets (including `banner.png`).
- **`orca_v1/`** — older ORCA Hand V1 design, useful for historical comparison:
  - **`ORCA_Assembly/`** — V1 assembly STEP model.
  - **`ORCA_Electronics/`** — V1 motor-connector BOM and `ORCA_Motor_Connectors_Gerber/` fabrication files.
  - **`ORCA_Fingers/`** — V1 finger geometry.
  - **`ORCA_Misc/`** — miscellaneous parts, including a camera mount.
  - **`ORCA_Molds/`** — V1 finger and palm skin mold models.
  - **`ORCA_Spools/`** — V1 tendon spool, ratchet, holder, and tensioning components.
  - **`ORCA_Tower/`** — V1 tower/actuator mounting, gearing, carpal, and support parts.
  - **`Print_Files_Bambu/`** — V1 Bambu Studio `.3mf` print projects for fingers, wrist, molds, spools, and tower.
- **`orca_v2/`** — original V2 source collection:
  - **`base/`** — original base V2 hand: the same component categories as the selected `full v2 hand files/` directory (`01_Fingers`, `02_Carpals`, `03_Wrist`, `04_ForeArm`, `05_Spools`, `06_CNC`, `07_Molds`, `09_Skin`, and `assembly-addendum`), plus base print projects, ZIP archives, and `ASSEMBLY_ADDENDUM.md`.
  - **`electronics/`** — original motor-connector BOM and `ORCA_Motor_Connectors_Gerber/` PCB fabrication files.
  - **`lite/`** — original simplified V2 part collection.
  - **`touch/`** — original touch-sensor V2 variant, including `01_Fingers/`, `02_Carpals/`, `09_OldPrintBeds/`, touch print/mold `.3mf` projects, and ZIP archives.
- **`scripts/`** — upstream Python utilities for managing `.3mf` projects:
  - `find_3mf_for_file.py` — identify which print projects contain a particular STL.
  - `update_3mf.py` — update or inspect STL references inside a `.3mf` project.
  - `update-print-files.py` — automate print-project updates from changed files.
  - `dedup_3mf.py` and `dedup_3mf_build_items.py` — utilities related to removing duplicate `.3mf` data/build items.
- **`package.json` / `package-lock.json`** — upstream package metadata and dependency lockfile; not necessary merely to open STL/STEP/3MF files.

## File formats

| Format | Purpose |
|---|---|
| `.3mf` | Pre-arranged 3D printing projects; open in a compatible slicer such as Bambu Studio. |
| `.stl` | Mesh geometry for printing and inspection. |
| `.step` | CAD exchange geometry useful for modifying mechanical designs. |
| `.zip` | Packaged original design files. |
| `.pdf` | Technical drawings and manufacturing documentation. |
| `.xls` | Original motor-connector PCB bill of materials. |
| Gerber / `.DRL` | PCB fabrication layers and drill data. |
| `.md` | Markdown documentation. |

## Planned development: Dynamixel AX-18A conversion

**Status: not started / not yet implemented in the stored design files.** My planned engineering sequence is:

1. **Document the baseline:** identify the original motor models, number of actuators, mounting points, tendon routing, and electrical interfaces.
2. **Check AX-18A mechanical compatibility:** body envelope, horn/output geometry, mounting-hole spacing, clearances, and service access.
3. **Redesign mounts and support structures:** prioritize the forearm/tower, wrist interface, and any actuator brackets that require modification.
4. **Review tendon transmission:** check spool geometry, horn coupling, cable travel, winding direction, friction, and tensioning.
5. **Review electrical and control interfaces:** verify power distribution, connectors, communication protocol, controller support, and actuator limits.
6. **Produce revised CAD and print files:** maintain a separate AX-18A design revision rather than overwriting original ORCA reference models.
7. **Prototype, assemble, and validate:** check mechanical fit, range of motion, tendon tension, repeatability, and thermal/electrical behavior.

Do not print or purchase AX-18A-specific hardware based solely on the current original motor-holder files; the conversion needs its own validated design.

## Credits and licensing

Original ORCA Hand project and design credit belongs to its respective creators and contributors. I have organized a copy of these files for UCF project development; I do not claim authorship of the original ORCA designs.

- [Official ORCA Hand website](https://www.orcahand.com/)
- [ORCA Hand hardware project](https://github.com/orcahand/orcahand_hardware)
- [Original ORCA files](https://github.com/orcahand/orca_files)
- [ORCA Hand fabrication and assembly tutorial](https://youtu.be/TgIz7HiyaoU?si=PWOCt1g08h2LHRF3)

**License note:** This repository currently has a root `LICENSE` file, while the archived upstream README identifies the ORCA design files as **CC BY 4.0**. Retaining original attribution and applicable upstream licensing is important; the presence of a root license does not automatically supersede the license of copied upstream material.

---

## BOM — Organized by Junyang (Completed)

> [!WARNING]
> **Do not use the original ORCA Hand README or official BOM as the purchasing authority for this project.** While organizing the BOM, I identified **multiple errors, omissions, and inconsistencies** in the official documentation. Some quantities, dimensions, and hardware revisions do not agree with the updated assembly instructions. The official files remain useful as design references, but **do not order components directly from their lists without checking my organized BOM and the actual CAD/assembly revision**.

**BOM organized by me (Junyang):** [`ORCA_Hand_V2_Complete_BOM_Organized_by_Junyang.xlsx`](ORCA_Hand_V2_Complete_BOM_Organized_by_Junyang.xlsx) — the component and procurement workbook I have already collected, checked, and organized for this project (October 2026). **The BOM organization task is complete; I do not need other team members to review or reorganize it at this stage.** I will handle any remaining technical verification marked `VERIFY`, `VERIFY CAD`, or similar before ordering.

The workbook contains the following worksheets:

| Worksheet | What it covers |
|---|---|
| `Read Me` | Scope, quantities, revision cautions, and sourcing notes. |
| `Common Hardware` | Bearings, pins, magnets, nuts, washers, and screws used across configurations. |
| `Tendons and PTFE` | UHMWPE tendon line, timing belt, and PTFE guide tubing. |
| `Printed and Silicone` | Printed parts, molds, PLA, silicone, and skin components. |
| `Franka Interface` | Optional mounting hardware when attaching the hand to a Franka robot arm. |
| `Dynamixel DX` | Original Dynamixel configuration: servos, power, communication, cooling, fasteners, and cables. |
| `Feetech FT` | Alternative Feetech configuration: servos, power, communication, cooling, fasteners, and cables. |

### BOM reference notes

1. **Build scope:** quantities are for **one hand (left or right)**. The original build uses **one** motor configuration (`Dynamixel DX` **or** `Feetech FT`), not both.
2. **Quantities:** `Assembly Qty` is the installed quantity; `Spare Qty` is the extra allowance; `Purchase Qty` includes listed spares. Units are indicated in the notes (for example, tendon length is in meters).
3. **Status:** `Confirmed` reflects the current BOM review, **not a guarantee that the item has been physically test-fitted**. `VERIFY`, `VERIFY CAD`, and other qualifications are flagged for my follow-up before ordering.
4. **Known conflicts:** the two wrist-bearing options (`6×13×5 mm` original and `8×13×4 mm` addendum) are **alternatives**. I will verify the selected CAD/revision; **both should not be purchased by default**. The addendum also introduces `Ø3×50 mm` carpal wrist pins and `Ø2×30 mm` thumb AP pins.
5. **PTFE and print revisions:** several PTFE diameters/lengths remain to be verified; the finger AP tube count assumes five AP parts. V1100 spools have **four** screw holes, whereas V1000 spools have **five**. I will match parts to the correct print revision.
6. **Optional hardware:** Franka interface components can be omitted if the hand uses another mounting arrangement.
7. **Pricing:** supplier, unit price, and extended-cost fields are intentionally available for procurement planning; blanks are **not** zero-cost items.

### Original actuator reference — not the AX-18A redesign

| Original configuration | Wrist actuator | Finger actuators |
|---|---|---|
| Dynamixel DX | `XC430-T240BB-T` × 1 | `XC330-T288-T` × 16 |
| Feetech FT | `HL-3930-Plastic` × 1 | `HL-2915-Plastic` × 16 |

These are **baseline reference configurations**, not motors I intend to purchase automatically. My intended **AX-18A conversion is future work**. I will re-evaluate the original motor counts and power/control parts for the redesigned system; the current workbook is **not yet an AX-18A-specific BOM**.

**Related resources:** [ORCA Hand official site](https://www.orcahand.com/) · [Full fabrication and assembly tutorial](https://youtu.be/TgIz7HiyaoU?si=PWOCt1g08h2LHRF3) · [`ASSEMBLY_ADDENDUM.md`](all%20files%20we%20corrently%20need/orca_v2/base_basic%20v2%20version%20start%20with%20this%20folder/full%20v2%20hand%20files/ASSEMBLY_ADDENDUM.md)
