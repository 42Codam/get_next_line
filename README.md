

# <p align="center">Project <a style="color:gray;text-decoration:none;" href="https://github.com/AtibQur/get_next_line/blob/master/en.subject.pdf">Get_next_line</a> 📖✍🏼️</h1>
<p><img align="right" src="score.png" alt="Score" width="125" height="125"></p>
<h2> Description Get_next_line</h2>   
<p>The goal of this project is to use the function <em>get_next_line();</em> to read from a file descriptor and return a line. Every time the function is called, an extra line returns until the last line is returned. <br>
The aim of this project is to learn how static variables work together with reading/writing lines from a file descriptor.
</p>

<h2>External functions 📚</h2>
<table>
  <tr>
    <td>read()</td>
    <td>read from a file descriptor</td>
  </tr>
  <tr>
    <td>malloc()</td>
    <td>malloc allocates memory and returns a pointer to it</td>
  </tr>
  <tr>
    <td>free()</td>
    <td>free deallocates the memory previously allocated by a call to malloc</td>
  </tr>
</table>

<h2>Installation</h2>
*To build the programm there is only a few steps: First of all, you can download the repository through the following steps in any shell of your preference:*
<br>
<pre>
git clone git@github.com:AtibQur/get_next_line.git
cd get_next_line
make
</pre>
These commands will compile everything and a executable "get_next_line" should be created. 
<br><br>
<h2>Usage 🛠️</h2>

<p>To compile the program, run the following command:</p>
<pre>
cd path_to_get_next_line && make
</pre>
<p>After creating the executable, you're able to use this program. <em>to use the program add the folowing as header in a file:</em></p>

<pre>
#include "get_next_line.h"
</pre>
<p>Create one or multiple .txt files and open() the file in the main function. Call get_next_line().</p>
<h2>Third-party testers</h2>
<li>Tripouille - gnlTester // https://github.com/Tripouille/gnlTester</li>
