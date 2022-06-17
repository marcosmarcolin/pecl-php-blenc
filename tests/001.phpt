--TEST--
Check for blenc presence
--SKIPIF--
<?php if (!extension_loaded("blenc")) print "skip"; ?>
--FILE--
<?php 
echo "blenc extension is available\n";
?>
--EXPECT--
Warning: Unknown: Failed to open stream: No such file or directory in Unknown on line 0

Warning: php_blenc_file_to_mem: Can't find or open file: '/usr/local/etc/blenckeys'. in Unknown on line 0

Warning: BLENC: Could not load some or all of the Keys in Unknown on line 0
blenc extension is available
