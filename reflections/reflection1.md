#Reflection 1

We set the goal for our first sprint to find out what our project should be, and research everything we need to know in order to do it. We successfully completed this to an extent, but we also missed the mark a bit. I now have a very clear understanding of what needs to be implemented, and what the algorithms are that need to be put in place. What I don’t have is how to do it well in C. I’m being blocked by not being comfortable enough with the language, and so I found that I spent a lot more time on the exercises and readings than I did on the project, because it was easier to think of specific implementation ideas for the exercises than the project. I feel more comfortable now with C than I did, and think that I can work on the project more effectively. 

We decided during our retrospective that we needed to have more consistent check ups, which I haven’t implemented very well mainly because this weekend in particular has been very busy. I still think that following Scrum more closely will improve our effectiveness, and will keep trying, and hopefully arrive at a better work balance that allows me to complete the exercises and work on the project.

One thing that we didn’t do particularly well during the sprint review was the exercises. We finished the reading on schedule, but didn’t finish the exercises with them. Since then, we all have been working on finishing those, and have been fairly successful so far. We’re going to make sure that we all have the required exercises done before next sprint review as well. We worked a lot on the project proposal last sprint, and so far haven’t worked much on the project since we’ve been doing exercises. As I mentioned earlier, we need to make sure that we find a balance and complete work in both areas, and make sure that we don’t miss the project this sprint.

##Exercises in C

[Exercise 1](../exercises/ex01)

[Exercise 2](../exercises/ex02)

[Exercise 2.5](../exercises/ex02.5)

##ThinkOS reading questions

[Reading Questions](../reading_questions/thinkos.md) Note that the answers are in title font.


##Exam Question

Lets say you initialize an integer array. 

int x[3] = {2, 30, -25};

What is the value of x[1]? What is the value of 1[x]? Explain why this is the case.


##Solution:

x[1] evaluates to 30, because x is a pointer, and the [] notation adds the offset inside the bracket to the memory address of the pointer. Thus, x[1] is equivalent to (address of x)+1. 

1[x] also evaluates to 30. The reason for this 
