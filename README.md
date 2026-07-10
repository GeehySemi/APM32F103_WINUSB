# APM32F103 WinUSB/CDC 虚拟串口示例 / APM32F103 WinUSB/CDC Virtual COM Port Example

[中文](#中文说明) | [English](#english)

## 中文说明

本项目基于 APM32F10x SDK V1.8，演示 APM32F103 USB Device 枚举为 CDC 虚拟串口，并与 Windows 主机进行数据通信。

### 示例功能

- APM32F103 枚举为 USB CDC 虚拟串口
- PC 通过串口工具发送数据
- 设备接收数据后原样回传
- 提供 USB Device 库、描述符及 CDC 示例源码

### 开发环境

| 项目 | 信息 |
| --- | --- |
| 目标板 | APM32F103 MINI |
| SDK | APM32F10x SDK V1.8 |
| 示例版本 | V1.0.3 |
| MDK | MDK-ARM V5.36 |
| IAR | EWARM V8.50.5.26295 |
| 示例目录 | `Examples/USB/USB_CDC_VirtualCOMPort` |

### 使用方法

1. 打开 `Project/MDK/USB_CDC_VirtualCOMPort.uvprojx`。
2. 检查 USB 引脚、时钟和目标器件配置。
3. 编译并下载程序至 APM32F103 MINI。
4. 通过 USB 将开发板连接到 Windows PC。
5. 在设备管理器中确认虚拟串口枚举成功。
6. 使用串口工具打开对应端口并发送数据，设备应回传相同内容。

### 注意事项

- 若系统未自动识别设备，请检查 USB 描述符、驱动绑定及 Windows 设备管理器状态。
- 修改 VID、PID 或接口描述符后，可能需要重新安装或更新主机端驱动。
- 本示例用于参考和开发验证，量产应用应补充异常恢复、缓冲区管理及 USB 合规性测试。

### 技术支持

更多产品资料与技术支持请访问：[www.geehy.com](https://www.geehy.com/)。

---

## English

Based on APM32F10x SDK V1.8, this project demonstrates how an APM32F103 USB device enumerates as a CDC Virtual COM Port and communicates with a Windows host.

### Features

- APM32F103 enumerates as a USB CDC Virtual COM Port
- A PC serial utility sends data to the device
- The device echoes received data back to the host
- USB device libraries, descriptors, and CDC example sources are included

### Development environment

| Item | Information |
| --- | --- |
| Target board | APM32F103 MINI |
| SDK | APM32F10x SDK V1.8 |
| Example version | V1.0.3 |
| MDK | MDK-ARM V5.36 |
| IAR | EWARM V8.50.5.26295 |
| Example directory | `Examples/USB/USB_CDC_VirtualCOMPort` |

### Usage

1. Open `Project/MDK/USB_CDC_VirtualCOMPort.uvprojx`.
2. Verify the USB pins, clocks, and target-device configuration.
3. Build and program the example to an APM32F103 MINI.
4. Connect the board to a Windows PC through USB.
5. Confirm that the Virtual COM Port enumerates in Device Manager.
6. Open the corresponding port in a serial utility and send data. The device should echo the same data.

### Notes

- If the device is not recognized automatically, check the USB descriptors, driver binding, and Windows Device Manager status.
- Changing the VID, PID, or interface descriptors may require reinstalling or updating the host driver.
- This example is for reference and development validation. Production applications should add error recovery, buffer management, and USB compliance testing.

### Support

For product information and technical support, visit [www.geehy.com](https://www.geehy.com/).
