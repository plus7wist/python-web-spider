import string;
import urllib2;
import re;

def download(begin, end):
  for i in range(begin, end + 1):
    fileName = 'poj/pro-' + string.zfill(i, 4);
    pageUrl = 'http://poj.org/problem?id=' + str(i);
    print 'from ' + pageUrl + ' to ' + fileName;
    with open(fileName, 'w') as fout:
      fout.write(urllib2.urlopen(pageUrl).read());

def printOneProTitle(html):
  # print html;
  beginDiv = '<div class="ptt" lang="en-US">';
  endDiv = '</div>'
  ptt = re.compile(beginDiv + '.*' + endDiv);
  mch = ptt.search(html);
  if (mch):
    print mch.group().replace(beginDiv, '').replace(endDiv, '');
  else:
    print 'null';

def printProTitle(begin, end):
  for i in range(begin, end + 1):
    pageUrl = 'http://poj.org/problem?id=' + str(i);
    print (str(i) + ':'),
    printOneProTitle(urllib2.urlopen(pageUrl).read());

def main():
  begin = int(raw_input(u'begin problem index:'));
  end = int(raw_input(u'end problem index:'));
  # download(begin, end);
  
  printProTitle(begin, end);

main();
