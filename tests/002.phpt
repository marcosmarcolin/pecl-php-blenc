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
Hello, World!
And again and again!
