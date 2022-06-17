--TEST--
Basic encode and decode
--SKIPIF--
<?php if (!extension_loaded("blenc")) print "skip"; ?>
--FILE--
<?php
    $content = file_get_contents("tests/input.php");
    $key = blenc_encrypt($content, "tests/output.phpe");

    //file_put_contents("tests/keys.txt", $key);
    include_once("tests/output.phpe");

    unlink("tests/output.phpe");
?>
--EXPECT--
Warning: Unknown: Failed to open stream: No such file or directory in Unknown on line 0

Warning: php_blenc_file_to_mem: Can't find or open file: '/usr/local/etc/blenckeys'. in Unknown on line 0

Warning: BLENC: Could not load some or all of the Keys in Unknown on line 0

Notice: blenc_encode: generate new key encoding key. in /home/tuukka/src/c/pecl-php-blenc/tests/002.php on line 3
Hello, World!
And again and again!
