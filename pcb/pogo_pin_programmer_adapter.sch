<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="connectors">
<description>&lt;b&gt;PCB Matrix Packages&lt;/b&gt;&lt;p&gt;</description>
<packages>
<package name="2X03">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-1.905" y1="3.81" x2="-2.54" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="3.81" x2="1.905" y2="3.81" width="0.1524" layer="21"/>
<wire x1="1.905" y1="3.81" x2="2.54" y2="3.175" width="0.1524" layer="21"/>
<wire x1="2.54" y1="3.175" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="3.175" x2="-2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-3.175" x2="-1.905" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-3.175" x2="1.905" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-3.81" x2="-1.905" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="-3.175" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="2.54" drill="1.016" shape="octagon" rot="R270" first="yes"/>
<pad name="2" x="1.27" y="2.54" drill="1.016" shape="octagon" rot="R270"/>
<pad name="3" x="-1.27" y="0" drill="1.016" shape="octagon" rot="R270"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="octagon" rot="R270"/>
<pad name="5" x="-1.27" y="-2.54" drill="1.016" shape="octagon" rot="R270"/>
<pad name="6" x="1.27" y="-2.54" drill="1.016" shape="octagon" rot="R270"/>
<text x="-3.81" y="4.445" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.81" y="-5.715" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="ISP_SURFACE">
<smd name="RST" x="0" y="0" dx="1.27" dy="1.27" layer="1"/>
<smd name="SCK" x="1.905" y="0" dx="1.27" dy="1.27" layer="1"/>
<smd name="MISO" x="3.81" y="0" dx="1.27" dy="1.27" layer="1" roundness="50"/>
<smd name="VTG" x="3.81" y="-1.905" dx="1.27" dy="1.27" layer="1"/>
<smd name="MOSI" x="1.905" y="-1.905" dx="1.27" dy="1.27" layer="1"/>
<smd name="GND" x="0" y="-1.905" dx="1.27" dy="1.27" layer="1"/>
<hole x="-1.905" y="0.635" drill="0.9"/>
<hole x="5.715" y="0.635" drill="0.9"/>
</package>
<package name="ISP_POGO">
<pad name="RST" x="0" y="0" drill="0.9" shape="offset" rot="R90"/>
<pad name="SCK" x="1.905" y="0" drill="0.9" shape="offset" rot="R90"/>
<pad name="MISO" x="3.81" y="0" drill="0.9" shape="offset" rot="R90"/>
<pad name="VTG" x="3.81" y="-1.905" drill="0.9" shape="offset" rot="R270"/>
<pad name="MOSI" x="1.905" y="-1.905" drill="0.9" shape="offset" rot="R270"/>
<pad name="GND" x="0" y="-1.905" drill="0.9" shape="offset" rot="R270"/>
<pad name="NC2" x="-1.905" y="0.635" drill="0.9" diameter="1.27" shape="long" rot="R90"/>
<pad name="NC1" x="5.715" y="0.635" drill="0.9" diameter="1.27" shape="long" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="ATMEL_ISP">
<pin name="VTG" x="-10.16" y="5.08" length="middle"/>
<pin name="MISO" x="-10.16" y="2.54" length="middle"/>
<pin name="SCK" x="-10.16" y="0" length="middle"/>
<pin name="RST" x="-10.16" y="-2.54" length="middle"/>
<pin name="MOSI" x="-10.16" y="-5.08" length="middle"/>
<pin name="GND" x="-10.16" y="-7.62" length="middle"/>
<wire x1="-5.08" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="-5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-10.16" x2="-5.08" y2="7.62" width="0.254" layer="94"/>
<text x="-5.08" y="7.62" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEL_ISP" prefix="JP">
<gates>
<gate name="G$1" symbol="ATMEL_ISP" x="15.24" y="-7.62"/>
</gates>
<devices>
<device name="" package="2X03">
<connects>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="MISO" pad="1"/>
<connect gate="G$1" pin="MOSI" pad="4"/>
<connect gate="G$1" pin="RST" pad="5"/>
<connect gate="G$1" pin="SCK" pad="3"/>
<connect gate="G$1" pin="VTG" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ISP_POGO">
<gates>
<gate name="G$1" symbol="ATMEL_ISP" x="12.7" y="-5.08"/>
</gates>
<devices>
<device name="SURFACE" package="ISP_SURFACE">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="MISO" pad="MISO"/>
<connect gate="G$1" pin="MOSI" pad="MOSI"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="SCK" pad="SCK"/>
<connect gate="G$1" pin="VTG" pad="VTG"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PROGRAMMER" package="ISP_POGO">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="MISO" pad="MISO"/>
<connect gate="G$1" pin="MOSI" pad="MOSI"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="SCK" pad="SCK"/>
<connect gate="G$1" pin="VTG" pad="VTG"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A4L-LOC" urn="urn:adsk.eagle:symbol:13874/1" library_version="1">
<wire x1="256.54" y1="3.81" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="256.54" y1="8.89" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="256.54" y1="13.97" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="256.54" y1="19.05" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="3.81" x2="161.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="24.13" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="215.265" y1="24.13" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="246.38" y1="3.81" x2="246.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="215.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="215.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<text x="217.17" y="15.24" size="2.54" layer="94">&gt;DRAWING_NAME</text>
<text x="217.17" y="10.16" size="2.286" layer="94">&gt;LAST_DATE_TIME</text>
<text x="230.505" y="5.08" size="2.54" layer="94">&gt;SHEET</text>
<text x="216.916" y="4.953" size="2.54" layer="94">Sheet:</text>
<frame x1="0" y1="0" x2="260.35" y2="179.07" columns="6" rows="4" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A4L-LOC" urn="urn:adsk.eagle:component:13926/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A4L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="JP1" library="connectors" deviceset="ATMEL_ISP" device=""/>
<part name="JP2" library="connectors" deviceset="ISP_POGO" device="PROGRAMMER"/>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="A4L-LOC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="JP1" gate="G$1" x="48.26" y="66.04" rot="MR0"/>
<instance part="JP2" gate="G$1" x="81.28" y="66.04"/>
<instance part="FRAME1" gate="G$1" x="-58.42" y="-25.4"/>
</instances>
<busses>
</busses>
<nets>
<net name="VTG" class="0">
<segment>
<pinref part="JP1" gate="G$1" pin="VTG"/>
<pinref part="JP2" gate="G$1" pin="VTG"/>
<wire x1="58.42" y1="71.12" x2="71.12" y2="71.12" width="0.1524" layer="91"/>
<label x="60.96" y="71.12" size="1.778" layer="95"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="JP2" gate="G$1" pin="MISO"/>
<pinref part="JP1" gate="G$1" pin="MISO"/>
<wire x1="71.12" y1="68.58" x2="58.42" y2="68.58" width="0.1524" layer="91"/>
<label x="60.96" y="68.58" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="JP1" gate="G$1" pin="SCK"/>
<pinref part="JP2" gate="G$1" pin="SCK"/>
<wire x1="58.42" y1="66.04" x2="71.12" y2="66.04" width="0.1524" layer="91"/>
<label x="60.96" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="RST" class="0">
<segment>
<pinref part="JP2" gate="G$1" pin="RST"/>
<pinref part="JP1" gate="G$1" pin="RST"/>
<wire x1="71.12" y1="63.5" x2="58.42" y2="63.5" width="0.1524" layer="91"/>
<label x="60.96" y="63.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="JP1" gate="G$1" pin="MOSI"/>
<pinref part="JP2" gate="G$1" pin="MOSI"/>
<wire x1="58.42" y1="60.96" x2="71.12" y2="60.96" width="0.1524" layer="91"/>
<label x="60.96" y="60.96" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="JP2" gate="G$1" pin="GND"/>
<pinref part="JP1" gate="G$1" pin="GND"/>
<wire x1="71.12" y1="58.42" x2="58.42" y2="58.42" width="0.1524" layer="91"/>
<label x="60.96" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
