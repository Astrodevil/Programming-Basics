# Comment Section Automation

Say you have the boring task of finding every phone number and email address in a comments section of a popular blog. If you manually scroll through the page, you might end up searching for a long time. But if you had a program that could search the text in your clipboard for phone numbers and email addresses, you could simply press ctrl-A to select all the text, press ctrl-C to copy it to a .txt file, and then run your program. It would fetch just the phone numbers and email addresses it finds and write them to another .txt file.

## Working and Output

I've fetched a few comments(ctrl-A) from a LinkedIn post and pasted them(ctrl-V) in a text file.
```
Pranay Raj Parisha  1st degree connection1st
Actively Looking forward to Summer Internships 2019
parishapranayraj97@gmail.com , 9833991285 Thank you for sharing!
Like Like Pranay Raj Parisha’s comment Reply
2d

MAYANK WADHWANI
MAYANK WADHWANI  1st degree connection1st
Events Executive at CSEA
please share a copy
mayank343@gmail.com
Like Like MAYANK WADHWANI’S comment Reply
6d

Priyam Sareen
Priyam Sareen  1st degree connection1st
Student at Indian Institute of Technology, Kanpur
please mail to sareenpriyam@gmail.com and call me at 022-2085-7292
Like Like Priyam Sareen’s comment Reply
3d

Hansa Maheshwari
Hansa Maheshwari  1st degree connection1st
Student at Indian Statistical Institute
furious.hansa@gmail.com
Like Like Hansa Maheshwari’s comment Reply
6d

Ayush Agarwala
Ayush Agarwala  1st degree connection1st
Tech enthusiast | Android app developer | Backend developer | BTECH CSE at NIT SILCHAR
ayush.code.05@gmail.com
Like Like Ayush Agarwala’s comment Reply
1w

Mayank Sharma
Mayank Sharma  1st degree connection1st
Student at SRM University
Pls share with me also  mayanksharma1902@gmail.com  (edited)

Like Like Mayank Sharma’s comment Reply
2h

Oindrila Choudhury
Oindrila Choudhury  2nd degree connection2nd
Student at SRM University
Hi , I would like to have a copy of it.  Email I'd oindie3@gmail.com
Like Like Oindrila Choudhury’s comment Reply
6h

Aravind Muthukrishnan
Aravind Muthukrishnan  3rd degree connection3rd
Quality Analyst at PM AM IT Services
Kindly share 1 copy with me at m_arvind93@yahoo.com
Thanks in advance
Like Like Aravind Muthukrishnan’s comment Reply
```
#### Output Obtained after running the script:

```
(['parishapranayraj97@gmail.com'], None, ['9833991285'])
(['mayank343@gmail.com'], None, None)
(['sareenpriyam@gmail.com'], ['022-2085-7292'], None)
(['furious.hansa@gmail.com'], None, None)
(['ayush.code.05@gmail.com'], None, None)
(['mayanksharma1902@gmail.com'], None, None)
(None, None, None)
(['oindie3@gmail.com'], None, None)
(['m_arvind93@yahoo.com'], None, None)
```
The script will create `PhoneandEmail.txt` file in the same directory and write the above output into it.

## Libraries Used:

`re — Regular expression operations`.  
For more information, refer this documentation: https://docs.python.org/3/library/re.html
