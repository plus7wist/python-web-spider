import string, urllib2;
   
def download(url, begin, end):
  for i in range(begin, end + 1):
    sName = string.zfill(i, 5) + '.html';
    pageUrl = url + '?pn=' + str(i);
    print 'from ' + pageUrl + ' to ' + sName;
    f = open(sName, 'w');
    html = urllib2.urlopen(pageUrl).read();  
    f.write(html);
    f.close();

url = str(raw_input(u'input page url without \'?pn=xx\'\n'));
begin = int(raw_input(u'begin index\n'));
end = int(raw_input(u'end index\n'));

download(url, begin, end);

