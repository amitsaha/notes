Rsyslog
-------

Agenda:

- rsyslog, logger
- rsyslog.conf: local socket, (imux sock., /dev/log)
- rsyslog in listening mode: accepting messages from remote logging clients
- rsyslog forwarding logging messages to remote rsyslog daemons
- C: http://www.gnu.org/software/libc/manual/html_mono/libc.html#Overview-of-Syslog  (Also: http://www.gnu.org/software/libc/manual/html_node/Overview-of-Syslog.html#Overview-of-Syslog)
- Python: http://docs.python.org/3/library/logging.handlers.html#sysloghandler
- Forwarding rules, others.
- Summary



In this post, I will talk about writing to local and remote rsyslog daemon using the command line program - logger, from a C program and from a Python program. Let's get started. 

Preliminaries
=============

First, let's check if you have rsyslog running::

    $ service rsyslog status

You should see a message such as "Active: active (running) since ..". Next, let's write a message to the syslog using the ``logger`` command line utility::

    $ logger "A logging message from logger"

Now, if you check your ``/var/log/messages`` file, and you should see the above message with a time stamp, your hostname and username prepending it, like so::

    Feb 25 12:36:46 fedora.echorand gene: A logging message from logger
    
By default, the ``rsyslog``
