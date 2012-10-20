jtech
=====

This is another attempt at a lightweight game engine written in C++.

It was inspired by an engine I worked on called hitest, which can be found
at the following address:

http://www.github.com/griffinmilsap/hitest/

***********************
UPDATE 10/20/2012:

Sorry about the long hiatus between the last update and this one. I have been
doing other things, and lost track of time. Since it is not appropriate to
write all of what I want to say in the log file, I'll start a small "blog"
about what is going on with the engine (I use "blog" is the loosest possible
terms: a log that is recorded on the web. None of that "I am a blogger so
I'm going to be pretentious" B.S.)

So, to business!

I have taken time to actually plan out how the engine is going to be structured,
so I am not going to be running into this blindly anymore. This being said, I 
have made the rough sketch of the engine layout available for viewing under the
docs folder. The current view is called "basic_engine_uml.png". Like I said, this
is a BASIC view of the engine's structure and IS GOING TO CHANGE OVER TIME! So,
please don't nag about how inefficient it looks. It's going to get better.

Another important detail is that I am going be using a particular file
convention for naming class files. It's pretty simple, but here it is anyway:

       [name].h/cpp

Simple! So, If I have a class called jFluffyBunny, I will have a header file
called jfluffybunny.h and jfluffybunny.cpp. This is important to have
documented in case somebody else decides to help out.

Another important thing to mention is the fact that the engine might not
be compiling for a little bit, due to excessive over-engieering of certain
aspects, such as possibly starting at the window creation portion of the engine
as opposed to the math portion of the engine (even though I have some math
related stuff already in there). I just want to get the platform dependent stuff
out of the way first (*cringes while saying* Win32 programming vs. X programming,
for instance).

Well, that should be all for now! Hopefully I'll be updating more frequently,
as well as adding to this "blog" post (most recent on top).

Catch you all later! --TPM
