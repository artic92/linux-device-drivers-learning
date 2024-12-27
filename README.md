# Linux Device Drivers Learning

![Build Status](https://github.com/artic92/linux-device-drivers-learning/actions/workflows/build_and_test.yaml/badge.svg)
![License](https://img.shields.io/github/license/artic92/linux-device-drivers-learning)
![Last Commit](https://img.shields.io/github/last-commit/artic92/linux-device-drivers-learning)
![Kernel Version](https://img.shields.io/badge/Kernel-6.0%2B-blue)

This repository summarises my progress into learning Linux device driver development. It follows the [LDD](https://lwn.net/Kernel/LDD3/) book.

---

## Getting Started

### Prerequisites

1. A Linux development environment with kernel headers installed.
2. Basic knowledge of C programming and Linux systems.
3. A desire to learn and explore!

### How to Use

1. Clone the repository:

   ```bash
   git clone https://github.com/username/linux-device-drivers-learning.git
   cd linux-device-drivers-learning
   ```

2. Navigate to the desired hello directory:

   ```bash
   cd hello_world/
   ```

3. Build the module:

   ```bash
   make
   ```

4. Load the module:

   ```bash
   sudo insmod hello.ko
   ```

5. Check kernel logs:

   ```bash
   dmesg | tail
   ```

6. Unload the module:

   ```bash
   sudo rmmod hello
   ```

---

## CI/CD Features

This repository employs GitHub Actions to:

- Verify that all kernel modules build successfully.
- Perform static code analysis for quality checks.
- Test modules in a virtualized environment (future goal).

---

## Contributing

Contributions are welcome! If you'd like to add hellos or improve existing code, please submit a pull request. Ensure that your code adheres to best practices and is thoroughly tested.

---

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- "Linux Device Drivers" by Jonathan Corbet, Alessandro Rubini, and Greg Kroah-Hartman for inspiration.
- Open-source community for invaluable tools and resources.

---

Happy coding and learning!
