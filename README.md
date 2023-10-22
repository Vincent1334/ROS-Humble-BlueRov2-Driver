# 🐢 ROS Humble BlueRov2 Driver 🌊

<p align="center">
  <img src="img/banner.jpg" />
</p>

## Getting Started
In this guide, we'll walk you through the process of setting up your development environment to work with ROS 2 Humble and a specific project repository on Ubuntu Jammy Jellyfish (22.04). Follow these steps to get started:

### 1. Install Ubuntu Jammy Jellyfish (22.04)
To begin, you'll need to install Ubuntu Jammy Jellyfish (22.04) on your computer. You can find installation instructions on the [Ubuntu website](https://ubuntu.com/download/desktop) or choose a suitable installation method for your system.

### 2. Install ROS 2 Humble
Next, you'll need to install ROS 2 Humble. Follow the official ROS 2 installation guide for Ubuntu development setup available at [ROS Humble](https://docs.ros.org/en/humble/Installation/Alternatives/Ubuntu-Development-Setup.html) to install ROS 2 on your system.

### 3. Clone the Project Repository
Now that you have Ubuntu Jammy Jellyfish and ROS 2 Humble installed, you can proceed to clone the project repository to your computer. Open a terminal and run the following command:

```bash
git clone https://github.com/Vincent1334/ROS-Humble-BlueRov2-Driver.git
```

This will download the project's source code to your local machine.

### 4. Install ROS Dependencies
Navigate to your ROS workspace's root directory and install the ROS dependencies using ROS 2's package manager, ***'rosdep'*** :

```bash
cd ~/ROS-Humble-BlueRov2-Driver
sudo rosdep init
rosdep update
rosdep install --from-paths src -y --ignore-src
```

### 5. Check Your BlueRov Configuration
Before you proceed further with the ROS 2 project, it's important to ensure that your BlueRov is configured correctly. Follow these steps to verify your BlueRov's configuration:

#### 5.1 BlueOS Installation

Make sure that your BlueRov is running "BlueOS" or an equivalent operating system that supports ROS 2 integration. BlueOS is a popular choice for ROVs and provides the necessary infrastructure to work with ROS 2.

#### 5.2 Mavlink Communication

ROS 2 relies on Mavlink communication to interact with your BlueRov. Ensure that your BlueRov is configured to establish Mavlink communication with your development environment. This typically involves configuring the communication settings on your ROV's companion computer or onboard computer.
