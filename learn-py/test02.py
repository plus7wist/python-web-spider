import urllib as ul;
import urllib2 as ul2;

try:
  1/0;
except Exception as e:
  print e.message;
else:
  print 'no exception';

