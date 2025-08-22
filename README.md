# DecaTime

DecaTime is a C project that provides tools for converting and displaying decimal time (French Revolutionary Time) alongside standard time. It consists of two main components:

- **realtime**: A real-time clock that displays both standard and decimal time in the terminal.
- **converter**: A command-line utility to convert between standard time and decimal time.

## Project Structure

```
.
├── Makefile
├── converter/
│   ├── converter.c
│   ├── Makefile
├── realtime/
│   ├── realtime.c
│   ├── Makefile
```

## Building the Project

To build both subprojects, run:

```sh
make
```

This will build both the `realtime` and `converter` executables using their respective Makefiles.

To clean all build artifacts:

```sh
make clean
```

## Usage

### Realtime Clock

Displays the current date, standard time, and decimal time, updating every 100ms.

```sh
cd realtime
./realtime
```

**Output Example:**
```
   14-06-2024 st: 13:45:30 dt: 05:73:14
```
- `st`: Standard time (HH:MM:SS)
- `dt`: Decimal time (HH:MM:SS, where 1 day = 10 hours, 1 hour = 100 minutes, 1 minute = 100 seconds)

### Converter

Converts between standard and decimal time.

```sh
cd converter
./converter <mode> <time>
```

- `<mode>`: `st` to convert standard time to decimal time, `dt` to convert decimal time to standard time
- `<time>`: Time in `HH:MM:SS` or `HH:MM` format

**Examples:**

Convert standard time to decimal time:
```sh
./converter st 14:30:00
```

Convert decimal time to standard time:
```sh
./converter dt 05:73:14
```

## License

(C)2025 koleq

---

See [`realtime/realtime.c`](realtime/realtime.c) and [`converter/converter.c`](converter/converter.c)