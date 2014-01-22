---
layout: default
title: Deployment Specification
---

# Deployment Specification

The [IDL module specification](module_spec.html) is convenient to be used together with our wrapper generating tools. It is strongly recommended not to do this stuff yourself. However, it is definitely possible to hook into architecture on a different level, namely on the **deployment** level.

## Specification details

The **deployment specification** is written in JSON. It contains the information on ports from the IDL specification, but appended with information required for deployment. The module specification can best be explained by example:

    {
    	"name":"MovingAverageModule",
    	"version":"42",
    	"type":"background",
    	"category":"general",
    	"description":"Calculates moving average with memory constraints O(1)",
    	"long_description": "Some very long description. Be careful with double quotes.",
    	"default_middleware": "zeromq",
    	"img_url": "https://raw.github.com/dobots/signalprocessing/movingaveragemodule/aim_config/assets/icon.png",
    	"supported_middleware":[ "yarp", "zeromq", "ros" ],
    	"supported_devices":[ "raspberrypi", "ubuntu" ],
    	"enable":"false",
    	"git": "https://github.com/dobots/signalprocessing.git",
    	"android": {
    		"package":"org.dobots.movingaveragemodule",
    		"url":"https://play.google.com/store/apps/details?id=org.dobots.movingaveragemodule"
    	},
    	"ports": [
    		{
    			"name":"input",
    			"dir":"in",
    			"type":"int",
    			"middleware":"default"
    		},
    		{
    			"name":"movingaverage",
    			"dir":"out",
    			"type":"int",
    			"middleware":"yarp"
    		}    	]
    }

### Name

Just as in the IDL module specification, the name should end with **Module**.

### Version

You can up the version of a module, to trigger recompilation and/or redeployment on devices.

### Type

The type of the module is important on an Android platform. There are currently two types supported: \"ui\", versus \"background\". Most often you will need the latter. However, in the case you want to put (graphical) user interface elements in the module, \"ui\" is required.

### Category

A free to be chosen category, currently there are categories such as:

* Chat
* Home automation
* Image processing
* Miscellaneous
* Robot
* Signal processing

### Description

A description of your module that can be used for example on the [Dodedodo](http://www.dodedodo.com) website to explain to users in a few lines what your module does.

### Long description

The long description can have more information on your module. Something like a paragraph or two would be fine. Refer to a website or github page for even more detailed information.

### Default middleware

This is the first option of choice on deploying a module on a specific platform.

### Img URL

An online reference to a picture that can be used to visualize your module.

### Supported middleware

If written using the tools provided by us, your module will run with all middlewares. However, in case this is no option for you, you can indicate which middlewares your software supports. 

### Supported devices

This is an important field. If you use platform specific tools, for example graphical user interface components from Android, your module becomes tied to that platform. This is okay, not all modules can be super generic, just indicate it using this field.

### Enable

In case you do not want to have your module running in the [Dodedodo](http://www.dodedodo.com) ecosystem, it can be enabled or disabled upfront using this flag.

### Git

The git repository where your module can be found. This is where this specification should exist.

### Android

Android specific instructions on how to deploy the module.

### Ports

A json representation of the information about ports from the IDL file.

