Hello everyone, today we have a release for some 3DS homebrew!
It's called Integrated3DS even though it looks quite simple it is work in progress.
We have implemented file detecting code to make it a bit accurate.

How does it work?:
For detecting if the user is using a9lh or b9s it looks for a boot.firm file.
It does this because a9lh uses "arm9loaderhax.bin" instead of boot.firm.
It detects TN or IPS displays using some code mostly GetVendors(&Screens).
To detect Operating System version it uses osGetKernelVersion.

Credits:
Credits to SciresM for TN or IPS code. The github link for SciresM's TN or IPS code github dot com/SciresM/ScreenInfo
Credits to devkitpro example creators.

Thank you to everyone!
Have a good day and we hope you enjoy Integrated3DS

Need help? Contact us on discord!
Discord code:8CpADk3
