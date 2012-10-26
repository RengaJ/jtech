jtech
=====

This is another attempt at a lightweight game engine written in C++.

It was inspired by an engine I worked on called hitest, which can be found
at the following address:

http://www.github.com/griffinmilsap/hitest/

***********************
UPDATE 10/25/2012:

Okay, so first thing's first...I have begun to overhaul the jVectorN set of classes.
This means a complete redux of jVector2,3 and 4. Why, you might ask? Well, because
I wasn't too pleased with having all of the implementation inside the header-files,
so if somebody was going to inherit the class (don't know who, but you never know!),
I wanted to hide my implementation details. Simply for security reasons.

Secondly, the skeleton for the graphics system has been posted! It's pretty big and
daunting at first glance, but it should make sense if you know UML. If you don't,
now is a good time to learn! I would recommend the following site:

http://edn.embarcadero.com/article/31863

It should give you some insight into what I was thinking, though I'm not strictly
following proper UML standards!

Anywho, hopefully these updates will become more frequent as I get more in gear
with the development of this engine. This will be in development for a while, so
keep an eye out for more updates!

Well, that's it for now. Onwards and upwards to the next great challenge!

-- TPM

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
