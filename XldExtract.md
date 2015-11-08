# Overview #

This is a utility for extracting the data from XLD archives to allow it to be analysed further and the test application for the XLD extraction code that's shared between other tools.

## Usage ##

```
xldextract <archive> <extension> <directory>
```

|Parameter|Description|Example|
|:--------|:----------|:------|
|archive  |The XLD archive from which the content should be extracted.|SONGS0.XLD|
|extension|The desired extension that the output files should have.|mid    |
|directory|The directory into which the extracted files should be saved.|c:\temp\|

## Supported On ##

  * Windows
  * Linux
  * OSX

## Source ##

The source is available [here](http://code.google.com/p/freealbion/source/browse/#svn/trunk/src/tools/xldextract)

## Current Limitations ##

The code needs a little work, which I am going to do very soon but because of this there are some caveats you should be aware of.

  1. All extracted content is named outN.ext where N is the position of the file in the archive, ext is the specified file extension. The 'out' part of the file name is static.

  1. Output file paths cannot exceed 255 characters in length.