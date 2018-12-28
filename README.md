

# STM32F103学习笔记

STM32F103基本外设的学习笔记，不定期更新。
![](https://wcc-blog.oss-cn-beijing.aliyuncs.com/img/stm32-img.jpg)

### 开发环境

软件环境：Keil v5.16a

主控芯片：STM32F103RET6，Flash 512KB，RAM 64KB，LQFP64。

调试器：Jlink V9

原理图：[v1.0.pdf](https://wcc-blog.oss-cn-beijing.aliyuncs.com/BlogFile/v1.0.pdf)

---

### 2018-12-27 01-Template

- 包含基本文件，内核文件，启动文件等
- 包含基本驱动库，sys，uart，delay，usmart
- 包含LED驱动、蜂鸣器驱动、按键驱动
- 添加批处理文件，可以在编译完成后自动删除垃圾文件
- 支持软件仿真，参数已经设置好
- 添加Astyle批处理命令，双击可以格式化当前目录下的所有源文件和头文件

------

### 2018-12-27 02-通用定时器定时功能

- 定时器初始化为溢出中断
- 定时器溢出中断服务函数为LED状态反转

---

### 2018-12-28 03-通用定时器产生PWM

- 定时器初始化为PWM输出，TIM3_CH1&CH2输出10KHz方波，占空比可调。
- 通过调节占空比，实现呼吸灯效果

---

我的个人博客：[我的博客](http://www.wangchaochao.top/)

我的公众号：

![](https://img2018.cnblogs.com/blog/1124009/201810/1124009-20181029203947824-323305888.jpg)

不定期更新电子电路、嵌入式方面的个人学习笔记和技术总结，欢迎互相学习交流！

------