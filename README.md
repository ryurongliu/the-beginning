# The Beginning
maxpatches and Arduino code for an audiovisual composition exploring God/the Machine/the Alien as philosophical Others, defined by opposition to the Self.
Video documentation found [here](https://youtu.be/VJZjwJz8DfI).

# Sound-Lights Synchronization
[final_lights](/final_lights): Arduino code driving Neopixels on the installation.

[brain.maxpat](maxpatches/BRAIN/brain.maxpat): patch driving sound-to-lights synchronization over serial. Uses custom-made "CV" audio files to provide synchronous light-controlling info. These "CV" files are omitted due to size and are available upon request. 

# Alien Instrument
This instrument sonifies the [1977 Wow! signal](https://en.wikipedia.org/wiki/Wow!_signal) detected by Ohio State University's Big Ear Telescope: a strong narrowband radio burst with no known origin. Potentially our first contact with extraterrestrial intelligence?

Two versions of the 'alien' instrument are provided: one with the original 7-channel mix, and one mixed to stereo. The stereo instrument is demonstrated below.

[![alien video demo](https://img.youtube.com/vi/fDmNikXRFVA/maxresdefault.jpg)](https://www.youtube.com/watch?v=fDmNikXRFVA)


# Universe Instrument
This instrument sonifies different power spectra of the [Cosmic Microwave Background](https://www.esa.int/articles/about-us/directorates/science/cosmic-microwave-background-cmb-radiation), echoes of the Big Bang. It implements the sonification scheme proposed by [McGee et al. 2011](https://www.researchgate.net/publication/235438516_Sonifying_the_Cosmic_Microwave_Background), using inverse-FFT synthesis to convert CMB power to amplitudes and CMP wavenumbers to frequencies. 

Calculations of different 'model universe' power spectra using different cosmological constants were done in Python: see Jupyter Notebook [cmb_models.ipynb](maxpatches/cmb_sounds.ipynb). 

Two versions of the universe instrument are provided: one with the original 7-channel mix, and one mixed to stereo. 

**WARNING: this patch uses up a lot of compute!! If your machine cannot handle mc objects with up to 285 channels, it may crash.** 

The stereo instrument is demonstrated below.

[![universe video demo](https://img.youtube.com/vi/ZumFJ8D4xU4/maxresdefault.jpg)](https://www.youtube.com/watch?v=ZumFJ8D4xU4)


