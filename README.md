<h1>0x16. C - Simple Shell</h1>
    <p>Written in C<br>
        Group project<br>
        Syscall<br>
        Done and Submitted by WisaniT and MichaelMwai
    </p>

 <h2>Mandatory Tasks</h2>

   <ol>
        <li><strong>0. Betty would be proud</strong><br>
            Write a beautiful code that passes the Betty checks
        </li>

   <li><strong>1. Simple shell 0.1</strong><br>
            Write a UNIX command line interpreter.
        </li>

   <li><strong>2. Simple shell 0.2</strong><br>
            Simple shell 0.1 +<br>
            Handle command lines with arguments
        </li>

   <li><strong>3. Simple shell 0.3</strong><br>
            Simple shell 0.2 +<br>
            Handle the PATH<br>
            fork must not be called if the command doesn’t exist
        </li>

   <li><strong>4. Simple shell 0.4</strong><br>
            Simple shell 0.3 +<br>
            Implement the exit built-in, that exits the shell<br>
            Usage: exit<br>
            You don’t have to handle any argument to the built-in exit
        </li>
<li><strong>5. Simple shell 1.0</strong><br>
            Simple shell 0.4 +<br>
            Implement the env built-in, that prints the current environment
        </li>
    </ol>
<h2>Advanced Tasks</h2>

   <ol>
        <li><strong>6. Simple shell 0.1.1</strong><br>
            Simple shell 0.1 +<br>
            Write your own getline function<br>
            Use a buffer to read many chars at once and call the least possible the read system call<br>
            You will need to use static variables<br>
            You are not allowed to use getline<br>
            You don’t have to:<br>
            - be able to move the cursor
        </li>

   <li><strong>7. Simple shell 0.2.1</strong><br>
            Simple shell 0.2 +<br>
            You are not allowed to use strtok<br>
            Repo:<br>
            GitHub repository: simple_shell
        </li>

   <li><strong>8. Simple shell 0.4.1</strong><br>
            Simple shell 0.4 +<br>
            handle arguments for the built-in exit<br>
            Usage: exit status, where status is an integer used to exit the shell
        </li>

   <li><strong>9. setenv, unsetenv</strong><br>
            Simple shell 1.0 +<br>
            Implement the setenv and unsetenv builtin commands<br>
            <strong>setenv</strong><br>
            Initialize a new environment variable, or modify an existing one<br>
            Command syntax: setenv VARIABLE VALUE<br>
            Should print something on stderr on failure<br>
            <strong>unsetenv</strong><br>
            Remove an environment variable<br>
            Command syntax: unsetenv VARIABLE<br>
            Should print something on stderr on failure
        </li>

   <li><strong>10. cd</strong><br>
            Simple shell 1.0 +<br>
            Implement the builtin command cd:<br>
            Changes the current directory of the process.<br>
            Command syntax: cd [DIRECTORY]<br>
            If no argument is given to cd the command must be interpreted like cd $HOME<br>
            You have to handle the command cd -<br>
            You have to update the environment variable PWD when you change directory<br>
            man chdir, man getcwd
        </li>

   <li><strong>11. ;</strong><br>
            Simple shell 1.0 +<br>
            Handle the commands separator ;
        </li>

   <li><strong>12. && and ||</strong><br>
            Simple shell 1.0 +<br>
            Handle the && and || shell logical operators
        </li>

   <li><strong>13. alias</strong><br>
            Simple shell 1.0 +<br>
            Implement the alias builtin command<br>
            Usage: alias [name[='value'] ...]<br>
            alias: Prints a list of all aliases, one per line, in the form name='value'<br>
            alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'<br>
            alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
        </li>

   <li><strong>14. Variables</strong><br>
            Simple shell 1.0 +<br>
            Handle variables replacement<br>
            Handle the $? variable<br>
            Handle the $$ variable
        </li>

   <li><strong>15. Comments</strong><br>
            Simple shell 1.0 +<br>
            Handle comments (#)
        </li>

   <li><strong>16. File as input</strong><br>
            Simple shell 1.0 +<br>
            Usage: simple_shell [filename]<br>
            Your shell can take a file as a command line argument<br>
            The file contains all the commands that your shell should run before exiting<br>
            The file should contain one command per line<br>
            In this mode, the shell should not print a prompt and should not read from stdin
        </li>
    </ol>
