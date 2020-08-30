<?php
class demo {
    public function get_site_name ($prefix) {
        return $prefix."信海龙的博客\n";
    }
}
function get_site_url ($prefix) {
    return $prefix."www.bo56.com\n";
}

function call_php_function ($obj, $fun, $param) {
    if ($obj == null) {
        $result = $fun($param);
    } else {
        $result = $obj->$fun($param);
    }
    return $result;
}
$demo = new demo();
echo call_function($demo, "get_site_name", "site name:");
echo call_function(null, "get_site_url", "site url:");
?>
